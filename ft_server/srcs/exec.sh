if [ $AUTOINDEX = 0 ]
then
mv /tmp/nginxoff.conf /tmp/nginx.conf
else
mv /tmp/nginxon.conf /tmp/nginx.conf
fi
mv /tmp/nginx.conf /etc/nginx/sites-available/localhost
service php7.3-fpm start
service nginx restart
service mysql restart
tail -f /dev/null
