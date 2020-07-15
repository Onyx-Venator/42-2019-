FROM debian:buster-20200514

RUN apt-get update -y && apt-get -y upgrade
RUN	apt-get install -y nginx
RUN	apt-get install openssl
RUN	apt-get install -y mariadb-server
RUN	apt-get install -y php7.3 php-fpm
RUN	apt-get install unzip

COPY srcs/phpMyAdmin-5.0.2-all-languages.zip /tmp/phpMyAdmin-5.0.2-all-languages.zip
RUN unzip /tmp/phpMyAdmin-5.0.2-all-languages.zip \
	&& mv /phpMyAdmin-5.0.2-all-languages /var/www/html

RUN openssl req -x509 -days 365 -newkey rsa:2048 -nodes -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=localhost" -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

COPY srcs/wordpress-5.4.2-fr_FR.zip /tmp/wordpress-5.4.2-fr_FR.zip
RUN unzip /tmp/wordpress-5.4.2-fr_FR.zip -d /var/www/html/
COPY srcs/wp-config.php /var/www/html/localhost/wordpress/wp-config.php

COPY srcs/nginx.conf /etc/nginx/sites-available/localhost

RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

RUN chown -R www-data:www-data /var/www/html/*
RUN chown 755 -R /var/www/html/*

COPY srcs/exec.sh /
COPY srcs/wp.sql /tmp/wp.sql

EXPOSE 80 443

CMD bash exec.sh
