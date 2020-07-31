if [ 1 ]
then
mv /tmp/nginxoff.conf /tmp/nginx.conf
else
mv /tmp/nginxon.conf /tmp/nginx.conf
fi
mv /tmp/nginx.conf /etc/nginx/sites-available/localhost
