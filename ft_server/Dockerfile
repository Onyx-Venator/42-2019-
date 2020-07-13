FROM debian:buster-20200514

RUN apt-get update -y && apt-get -y upgrade
RUN	apt-get install -y nginx
RUN	apt-get install openssl
RUN	apt-get install -y mariadb-server
RUN	apt-get install -y php7.3 php-fpm
RUN	apt-get install unzip

RUN mkdir -p /var/www/html/localhost

COPY srcs/phpMyAdmin-5.0.2-all-languages.zip /tmp/phpMyAdmin-5.0.2-all-languages.zip
RUN unzip /tmp/phpMyAdmin-5.0.2-all-languages.zip \
	&& mv /phpMyAdmin-5.0.2-all-languages /var/www/html/localhost

RUN cd /var \
	&& mkdir cert \
	&& cd cert \
	&& openssl req -new -newkey rsa:2048 -nodes -out self_certif.csr -keyout self_certif.key -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=localhost" \
	&& openssl x509 -req -days 365 -in self_certif.csr -signkey self_certif.key -out self_certif.crt

COPY srcs/wordpress-5.4.2-fr_FR.zip /tmp/wordpress-5.4.2-fr_FR.zip
RUN unzip /tmp/wordpress-5.4.2-fr_FR.zip -d /var/www/html/localhost
COPY srcs/wp-config.php /var/www/html/localhost/wordpress/wp-config.php
RUN chown -R www-data:www-data /var/www/html/localhost

RUN rm -f /etc/nginx/sites-enabled/default \
	&& ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/

COPY srcs/nginx.conf /ect/nginx/sites-available/localhost

EXPOSE 80 443

COPY srcs/wp.sql /tmp/wp.sql
CMD #service nginx start \
	#&& service php7.3-fpm start \
	&& service mysql start \
	&& mysql -u root < /tmp/wp.sql \
	&& bash exec.sh
