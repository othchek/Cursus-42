#include "../../inc/irc_server.hpp"

const char* SERVSOCKET::ErrorOnSocket::what() const throw()
{
    return "Error";
}

void SERVSOCKET::mysocket(int ipvs, const int type)
{
    socket_server = socket(ipvs, type, 0);
    if (socket_server == -1)
        throw ErrorOnSocket();
}

void SERVSOCKET::mybind(std::string ip, int port)
{
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (bind(socket_server, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        close(socket_server);
        throw ErrorOnSocket();
    }
}

void SERVSOCKET::mylisten(int nb_client)
{
    if (listen(socket_server, nb_client) == -1)
    {
        close(socket_server);
        throw ErrorOnSocket();
    }
}

void SERVSOCKET::myaccept()
{
    std::string username;
    std::string password;
    std::string nickname;

    socklen_t clientAddressSize = sizeof(client_addr);
    socket_client = accept(socket_server, (struct sockaddr*)&client_addr, &clientAddressSize);
    if (socket_client == -1)
    {
        close(socket_server);
        throw ErrorOnSocket();
    }
    mysend("USERNAME: ");
    username = myrecv(1024);
    mysend("NICKNAME: ");
    nickname = myrecv(1024);
    mysend("PASSWORD: ");
    password = myrecv(1024);
    database[username] = password;
    mysend("------- WELCOME TO THE SERVER ------\n");
}

std::string SERVSOCKET::myrecv(unsigned int size)
{
    char buffer[size];
    ssize_t num_read;

    num_read = recv(socket_client, buffer, sizeof(buffer), 0);
    buffer[num_read] = '\0';
    if (num_read <= 0)
    {
        throw ErrorOnSocket();
    }
    return buffer;
}

void SERVSOCKET::mysend(std::string data)
{
    if (send(socket_client, data.c_str(), data.length(), 0) == -1)
        throw ErrorOnSocket();
}

void SERVSOCKET::show()
{
    std::map<std::string, std::string>::iterator it;
    for (it = database.begin(); it != database.end() ;it++) {
        std::cout << "username = " << it->first;
        std::cout << "password = " << it->second;
    }
}