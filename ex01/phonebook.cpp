#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldcontact = 0;
}
void    PhoneBook::addContact()
{
    contacts[oldcontact].setInfo();
    oldcontact = (oldcontact + 1) % 8;
    if (contactCount < 8)
        contactCount++;
    std::cout << "contact added\n";
}

void    PhoneBook::searchContact()
{
    std::string input;

    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty.\n";
        return ;
    }
    std::cout << "|   Index  |First Name|Last Name |Nickname  |\n";
    for (int i = 0; i < contactCount; i++)
        contacts[i].displayBrief(i);
    while (true)
    {
        std::cout << "Enter index for more details: ";
        std::getline(std::cin, input);

        if (std::cin.eof())
            exit(0);

        if (input.size() == 1 && std::isdigit(input[0]) && (input[0] - '0') < contactCount)
        {
            contacts[input[0] - '0'].displayall();
            break ;
        }
        else
            std::cout << "Invalid Index! Try again.\n";
    }
}