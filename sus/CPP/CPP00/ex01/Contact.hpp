#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        std::string getter_firstname (void);
        std::string getter_lastname (void);
        std::string getter_nickname (void);
        std::string getter_phone_number (void);
        std::string getter_darkest_secret (void);
        void setter_firstname (std::string str);
        void setter_lastname (std::string str);
        void setter_nickname (std::string str);
        void setter_phone_number (std::string str);
        void setter_darkest_secret (std::string str);
};

#endif