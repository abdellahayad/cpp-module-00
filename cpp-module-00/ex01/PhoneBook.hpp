#include <string>
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

    
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
  