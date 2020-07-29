CREATE DATABASE wp_bdd;
GRANT ALL PRIVILEGES on wp_bdd.* TO 'root'@localhost;
FLUSH PRIVILEGES;
update mysql.user set plugin = 'mysql_native_password' where user='root';
