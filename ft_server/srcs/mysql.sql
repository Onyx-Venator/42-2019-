CREATE USER 'wp_user'@localhost IDENTIFIED BY 'wp_user';
CREATE DATABASE wp_bdd;
GRANT ALL PRIVILEGES on wp.* to 'wp_user'@localhost;
FLUSH PRIVILEGES;
