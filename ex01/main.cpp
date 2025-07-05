#include "PhoneBook.h"

int main()
{
    PhoneBook phonebook;
    std::string cmd;


    while (1)
    {
        std::cout << "Enter Command (ADD, SEARCH, EXIT)" << std::endl;
        if (!getline(std::cin, cmd))
            break;
     
        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "EXIT")
            break ;
    }
    return (0);
}