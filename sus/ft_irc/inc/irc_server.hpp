#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <map>

class SERVSOCKET
{
    public:
        sockaddr_in server_addr;
        int socket_server;
        sockaddr_in client_addr;
        int socket_client;
        std::map<std::string, std::string> database;

    public:
        void mysocket(int ipvs, const int type);
        void mybind(std::string ip, int port);
        void mylisten(int nb_client);
        void myaccept(void);
        std::string myrecv(unsigned int size);
        void mysend(std::string data_send);
        void show();

        class ErrorOnSocket : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};