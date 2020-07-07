FROM debian:buster-20200514

RUN apt-get update -y && apt-get -y upgrade && \
	apt-get install nginx && \
	apt-get install openssl && \
	apt-get install mariadb && \
	apt-get install php7.3 -phpfpm

RUN mkdir -p /var/www/html/ft_server.com

COPY srcs/phpMyAdmin-5.0.2-all-languages.zip /tmp/phpMyAdmin-5.0.2-all-languages.zip
RUN tar -xf /tmp/phpMyAdmin-5.0.2-all-languages.zip \
	&& mv /tmp/phpMyAdmin-5.0.2-all-languages /var/www/html/ft_server.com

RUN cd /var \
	&& mkdir cert \
	&& cd cert \
	&& openssl req -new -newkey rsa:2048 -nodes -out self_certif.csr -keyout self_certif.key -subj "/C=FR/ST=IDF/L=Paris/O=42/CN=ft_server.com" \
	&& openssl x509 -req -days 365 -in self_certif.csr -signkey self_certif.key -out self_certif.crt

COPY srcs/wordpress-5.4.2-FR.zip /tmp/wordpress-5.4.2-FR.zip
RUN tar -xf /tmp/wordpress-5.4.2-FR.zip \
	&& mv /tmp/wordpress-5.4.2-FR /var/www/html/ft_server.com
COPY srcs/wp-config.php /var/www/html/ft_server.com/wordpress/wp-config.php
RUN chown -R www-data:www-data /var/www/html/ft_server.com

Run rm -f /etc/nginx/site-enabled/default \
	&& ln -s /ect/nginx/sites-available/ft_server.com /ect/nginx/sites-enabled/

COPY srcs/nginx.cong /ect/nginx/sites-available/ft_server.com

EXPOSE 80 443

COPY srcs/wp.sql /tmp/wp.sql
CMD service nginx start \
	&& service php7.4-fpm start \
	&& service mysql start \
	&& mysql -u root < /tmp/wp.sql \
	&& sh
