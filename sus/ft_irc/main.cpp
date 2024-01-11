#include "./inc/channel.hpp"
#include "./inc/irc_server.hpp"
#define PORT 12321

int main() 
{
	channel obj;
    try
    {
        SERVSOCKET server;
        std::string data;
        
        server.mysocket(AF_INET, SOCK_STREAM);
        server.mybind("127.0.0.1", PORT);
        server.mylisten(5);

        std::cout << "Server listening on port " << PORT<< " ..." << std::endl;
        server.myaccept();
        std::cout << "------- MY SERVER ------" << std::endl;
        	while (true)
        	{
				try {
        	    	data = server.myrecv(1024);
					obj.channel_parse(data);
        	    	// std::cout << data << std::endl;
        	    	// server.mysend(data);
        	    	// server.show();
				}
				catch (const char *data) {
					std::cout << RED << data << RESET << std::endl;
				}
		}
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // close(clientSocket);
    // close(serverSocket);

    return 0;
}