FROM debian:oldstable

WORKDIR /var/www

RUN rm -rf *
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y vim curl php php-fpm php-mysql
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN sed -i "s|listen = /run/php/php7.4-fpm.sock|listen = 9000|g" /etc/php/7.4/fpm/pool.d/www.conf
RUN mkdir -p /run/php

COPY ./tools/daw.sh .

RUN  chmod +x daw.sh

CMD  ["./daw.sh"]
