FROM    debian:oldstable

RUN     apt-get update -y && apt-get install -y vim
RUN     apt install -y nginx
RUN     apt install -y openssl
RUN     mkdir -p /etc/nginx/ssl && chmod 777 /etc/nginx/ssl
RUN     openssl req -x509 -new -newkey rsa:2048 -nodes \
        -out /etc/nginx/ssl/otchekai.crt \
        -keyout /etc/nginx/ssl/otchekai.key \
        -subj "/C=MA/ST=Béni Mellal-Khénifra/L=Khouribga/O=42/OU=42/CN=otchekai.42.fr/UID=otchekai"

COPY    ./conf/nginx.conf /etc/nginx/sites-available/default
COPY    ./conf/index.html /home

EXPOSE  443

ENTRYPOINT    ["nginx", "-g", "daemon off;"]