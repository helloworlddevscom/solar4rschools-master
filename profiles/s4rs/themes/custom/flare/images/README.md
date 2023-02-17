### Alphecca images

If you're not using the most current version Turnip (cf0e422dac) to spin up
your theme, you'll need to manually add a symlink in your theme's images directory
pointing to Alphecca's images: `images -> ../../../vendor/alphecca/images`.

Be sure to duplicate the directory structure in your images folder, creating
directories for `vendor` and `alphecca` so that from the root of your theme
`images/vendor/alphecca/images` points to `vendor/alphecca/images`.
