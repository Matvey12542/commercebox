Place downloaded and custom libraries that extend your site functionality beyond
Drupal core in this directory to ensure clean separation from core libraries and
to facilitate safe, self-contained code updates.

It is safe to organize libraries into subdirectories, such as "contrib" for
contributed libraries, and "custom" for custom libraries.

In multisite configuration, libraries found in this directory are available to
all sites. Alternatively, the sites/your_site_name/libraries directory pattern
may be used to restrict libraries to a specific site instance.
