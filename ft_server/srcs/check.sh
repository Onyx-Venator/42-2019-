if $INDEX = 1
@mv /tmp/nginxoff.conf /tmp/nginx.conf
else
@mv /tmp/nginxon.conf /tmp/nginx.conf
endif
@mv /tmp/nginx.conf /etc/nginx/sites-available/localhost
