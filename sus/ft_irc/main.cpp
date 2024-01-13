#include "./inc/servsocket.hpp"
#include "./inc/channel.hpp"

int main(int ac, char** av) 
{

    if (ac != 3) {
            std::cerr << RED"Invalid arguments"RESET << std::endl;
            exit (1);
    }
    SERVSOCKET server;
    channel obj;
    std::string data;
    std::string port;
        
    port = av[1];
    server.servpass = av[2];
    int server_fd = server.mysocket(AF_INET, SOCK_STREAM);
    server.mybind("127.0.0.1", std::stoi(port));
    server.mylisten(5);

    std::cout << GREEN << "------- MY SERVER ------" << RESET << std::endl;
    std::cout << PURPLE << "Server Listening on port " << port << " ..." << RESET << std::endl;

    POLLFD vector;
    int client_fd;
    size_t i = 0;

    vector.push(server_fd, POLLIN, 0);
    while (true)
    {
        try 
        {
            poll(vector.vector.data(), vector.vector.size(), -1);
            i = 0;
            while (i < vector.vector.size())
            {
                if (vector.vector[i].revents & POLLIN)
                {
                    if (vector.vector[i].fd == server_fd)
                    {
                        client_fd = server.myaccept();
                        vector.push(client_fd, POLLIN, 0);
                    }
                    else
                    {
                        data = server.myrecv(1024, vector.vector[i].fd);
                        obj.channel_parse(data);
                        std::cout << data << std::endl;
                    }
                }
                i++;
            }
        }
        catch (const char *str) {
            std::cerr << str << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            if (i)
            {
                close(vector.vector[i].fd);
                vector.vector.erase(vector.vector.begin() + i);
            }
        }
    }
        return 0;
}
