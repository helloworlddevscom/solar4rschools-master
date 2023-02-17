<?php

/**
 * Created by PhpStorm.
 * User: dan
 * Date: 3/29/16
 * Time: 6:16 PM
 */
class LocusEnergyApi
{

  const API_BASE = 'https://api.locusenergy.com/';


  const TOKEN_REQUEST_URL = 'https://api.locusenergy.com/oauth/token';


  const TOKEN_CACHE = 'locus-energy-access-token';

  /* Number of seconds before a token expires to try to get a new one */
  const TOKEN_EXPIRES_WITHIN = 10;


  protected $clientId;


  protected $clientSecret;


  protected $token;


  public static $_instance;


  public function __construct()
  {
    $this->authenticate();
  }


  public static function instance()
  {
    if( !isset(self::$_instance) ) {
      $api = new LocusEnergyApi();
      self::$_instance = $api;
    }
    return self::$_instance;
  }


  public static function setUsername($username)
  {
    variable_set('locus_energy_username', $username);
  }


  public static function setPassword($password)
  {
    variable_set('locus_energy_password', $password);
  }


  public static function setClientId($clientId)
  {
    variable_set('locus_energy_client_id', $clientId);
  }


  public static function setClientSecret($clientSecret)
  {
    variable_set('locus_energy_client_secret', $clientSecret);
  }


  public function getPassword()
  {
    return variable_get('locus_energy_password');
  }


  public function getUsername()
  {
    return variable_get('locus_energy_username');
  }


  public function getClientId()
  {
    return variable_get('locus_energy_client_id');
  }


  public function getClientSecret()
  {
    return variable_get('locus_energy_client_secret');
  }


  public function getPersistedToken()
  {
    return variable_get('locus_energy_token');
  }


  public function isTokenExpired(stdClass $token)
  {
    return time() >= ($token->issued_at + $token->expires_in) - self::TOKEN_EXPIRES_WITHIN;
  }


  public function persistToken(stdClass $token)
  {
    variable_set('locus_energy_token', $token);
  }


  public function cacheToken(stdClass $token)
  {
    cache_set(self::TOKEN_CACHE, $token, 'cache', $token->issued_at + $token->expires_in);
  }


  public function getCachedToken()
  {
    $cache = cache_get(self::TOKEN_CACHE);

    if($cache && $cache->expire > time()) {
      return $cache->data;
    }

    return FALSE;
  }


  protected function getAccessToken($clientId, $clientSecret, $username, $password)
  {
    $url = self::TOKEN_REQUEST_URL;

    $data = sprintf('grant_type=password&client_id=%s&client_secret=%s&username=%s&password=%s', $clientId, $clientSecret, $username, $password);
    $request_time = time();
    $response = drupal_http_request($url, array(
      'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      'method' => 'POST',
      'data' => $data
    ));
    $log_data = array(
      'request_url' => $url,
      'request_data' => $data,
      'response_code' => $response->code,
      'response_data' => $response->data,
      'request_timestamp' => $request_time,
      'response_timestamp' => time(),
    );
    drupal_write_record('locus_api_log', $log_data);

    locus_energy_increment_api_call();

    if ($response->code !== "200") {
      $message = 'Locus Energy authentication error for @username at @path. Response: HTTP @code (@status) @error';
      $args = array(
        '@username' => $username,
        '@path' => self::TOKEN_REQUEST_URL,
        '@code' => isset($response->code) ? $response->code : NULL,
        '@status' => isset($response->status_message) ? $response->status_message : NULL,
        '@error' => isset($response->data) ? $response->data : NULL,
      );
      watchdog('locus_energy', $message, $args, WATCHDOG_ERROR);
      return FALSE;
    }

    $token = json_decode($response->data);

    $token->issued_at = time();

    return $token;
  }


  public function refreshAccessToken(stdClass $token, $clientId, $clientSecret)
  {
    $data = sprintf('grant_type=refresh_token&client_id=%s&client_secret=%s&refresh_token=%s', $clientId, $clientSecret, $token->refresh_token);
    $request_time = time();
    $response = drupal_http_request(self::TOKEN_REQUEST_URL, array(
      'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
      'method' => 'POST',
      'data' => $data,
    ));
    $log_data = array(
      'request_url' => self::TOKEN_REQUEST_URL,
      'request_data' => $data,
      'response_code' => $response->code,
      'response_data' => $response->data,
      'request_timestamp' => $request_time,
      'response_timestamp' => time(),
    );
    drupal_write_record('locus_api_log', $log_data);

    locus_energy_increment_api_call();

    if ($response->code !== "200") {
      $message = 'Locus Energy refresh token error for @method @path. Request data: @data Response: HTTP @code (@status) @error';
      $args = array(
        '@method' => 'POST',
        '@path' => self::TOKEN_REQUEST_URL,
        '@data' => $data,
        '@code' => isset($response->code) ? $response->code : NULL,
        '@status' => isset($response->status_message) ? $response->status_message : NULL,
        '@error' => isset($response->data) ? $response->data : NULL,
      );
      watchdog('locus_energy', $message, $args, WATCHDOG_ERROR);
      return FALSE;
    }

    $token = json_decode($response->data);

    $token->issued_at = time();

    return $token;
  }


  public function isAuthenticated()
  {
    return isset($this->token) && !$this->isTokenExpired($this->token);
  }


  public function authenticate()
  {
    if ($token = $this->getCachedToken()) {
      if ( !$this->isTokenExpired($token)) {
        $this->token =  $token;
        return TRUE;
      }

    }

    $clientId = $this->getClientId();
    $clientSecret = $this->getClientSecret();

    if( !$clientId && !$clientSecret ) {
      return FALSE;
    }

    $token = $this->getPersistedToken();
    if ($token && $this->isTokenExpired($token)) {
      $token = $this->refreshAccessToken($token, $clientId, $clientSecret);
    }

    if (!$token) {
      $username = $this->getUsername();
      $password = $this->getPassword();
      if (!$username && !$password) {
        return FALSE;
      }

      $token = $this->getAccessToken($clientId, $clientSecret, $username, $password);
    }

    if( !$token ) {
      return FALSE;
    }

    $this->persistToken($token);
    $this->cacheToken($token);

    $this->token =  $token;
    return TRUE;
  }


  public function getApiCallCacheKey($endpoint) {
    return 'API-RESPONSE:' . $endpoint;
  }


  public function call($endpoint, array $options = array())
  {

    if( !$this->isAuthenticated() )  {
      $successful = $this->authenticate();
      if( !$successful ) {
        return FALSE;
      }
    }

    $path = self::API_BASE . $endpoint;

    if( !isset($options['method']) ) {
      $options['method'] = 'GET';
    }

    $options['headers'] = array(
      'Accept' => 'application/json',
      'Authorization' => 'Bearer ' . $this->token->access_token
    );


    if($status = $this->isApiCallLocked()) {
      $count = 0;
      do {
        $count++;
        if ($count > 30) {
          $response = new stdClass();
          $response->statusCode = 429;
          return $response;
        }
        sleep(1);
        $status = $this->isApiCallLocked();
      } while ($status);
    }


    $this->setApiLocked();
    $request_time = time();
    $response = drupal_http_request($path, $options);
    $log_data = array(
      'request_url' => $path,
      'request_data' => $options,
      'response_code' => $response->code,
      'response_data' => $response->data,
      'request_timestamp' => $request_time,
      'response_timestamp' => time(),
    );
    drupal_write_record('locus_api_log', $log_data);

    $this->setApiUnlocked();

    locus_energy_increment_api_call();

    if ($response->code !== "200") {
      $message = 'Locus Energy REST error for @method @path. Response: HTTP @code (@status) @error';
      $args = array(
        '@method' => $options['method'],
        '@path' => $path,
        '@code' => isset($response->code) ? $response->code : NULL,
        '@status' => isset($response->status_message) ? $response->status_message : NULL,
        '@error' => isset($response->data) ? $response->data : NULL,
      );
      watchdog('locus_energy', $message, $args, WATCHDOG_ERROR);
      return FALSE;
    }

    $data = json_decode($response->data);

    return $data;
  }


  public function isApiCallLocked() {
    $result = db_select('variable', 'v')->fields('v', array('value'))->condition('name', 'locus_energy_api_lock', '=')->execute()->fetchAssoc();
    $serialized = reset($result);
    $data = unserialize($serialized);

    if (($data['locked_at'] + 120) < time()) {
      $this->setApiUnlocked();
      return FALSE;
    }

    return $data['locked'];
  }


  public function setApiLocked() {
    variable_set('locus_energy_api_lock', array('locked'=> TRUE, 'locked_at' => time()));
  }


  public function setApiUnlocked() {
    variable_set('locus_energy_api_lock', array('locked'=> FALSE, 'locked_at' => time()));
  }


  public static function getComponent($componentId)
  {
    return self::instance()->call('v3/component/' . $componentId);
  }


  public static function getComponentsForSite($siteId)
  {
    return self::instance()->call('v3/sites/' . $siteId . '/components');
  }


  public static function getComponentsForClient($clientId)
  {
    return self::instance()->call('v3/clients/' . $clientId . '/components');
  }


  public static function getSite($siteId)
  {
    return self::instance()->call( 'v3/clients/' . $siteId );
  }


  public static function getSitesForClient($clientId)
  {
    return self::instance()->call('v3/clients/' . $clientId . '/sites');
  }


  public static function getSitesForPartner($partnerId)
  {
    return self::instance()->call('v3/partners/' . $partnerId . '/sites');
  }


  public static function getSiteInstallInfo($siteId)
  {
    return self::instance()->call('v3/sites/' . $siteId . '/installinfo');
  }


  public static function getSiteModelSettings($siteId)
  {
    return self::instance()->call('v3/sites/' . $siteId . '/modelsettings');
  }


  public static function getClient($clientId)
  {
    return self::instance()->call('v3/clients/' . $clientId);
  }


  public static function getDataAvailableForComponent($componentId)
  {
    return self::instance()->call('v3/components/' . $componentId . '/dataavailable');
  }


  public static function getDataAvailableForSite($siteId)
  {
    return self::instance()->call('v3/sites/' . $siteId . '/dataavailable');
  }


  public static function getDataForComponent($componentId, array $fields, $start, $end, $granularity, $tz)
  {
    $query = drupal_http_build_query(array(
      'fields' => implode(',', $fields),
      'start' => $start,
      'end' => $end,
      'tz' => $tz,
      'gran' => $granularity
    ));

    return self::instance()->call('v3/components/' . $componentId . '/data?' . $query);
  }


  public static function getDataForSite($siteId,  array $fields, $start, $end, $granularity, $tz)
  {
    $query = drupal_http_build_query(array(
      'fields' => implode(',', $fields),
      'start' => $start,
      'end' => $end,
      'tz' => $tz,
      'gran' => $granularity
    ));
    return self::instance()->call('v3/sites/' . $siteId . '/data?' . $query);
  }
}
