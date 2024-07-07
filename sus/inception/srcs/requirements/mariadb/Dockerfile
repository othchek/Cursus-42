FROM    debian:oldstable

RUN     apt-get update -y && apt upgrade -y && apt-get install -y vim
RUN     apt install mariadb-server mariadb-client -y
RUN     mkdir -p /var/run/mysqld && chown -R mysql /var/run/mysqld && chmod -R 777 /var/run/mysqld
RUN     sed -i "s|bind-address            = 127.0.0.1|bind-address            = 0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

COPY    ./tools/dawdaw.sh .

RUN     chmod +x dawdaw.sh

CMD     ["./dawdaw.sh"]