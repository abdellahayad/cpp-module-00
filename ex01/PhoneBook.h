#include <string>
#include "Contact.h"
#include <iostream>
#include <iomanip>

class PhoneBook {

    private:
        Contact contacts[8];
        int     contactCount;
        int     oldcontact;
    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
};