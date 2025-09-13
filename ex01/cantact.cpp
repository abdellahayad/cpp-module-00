#include "PhoneBook.h"

bool Contact::isValidInput(const std::string& input)
{
    if (input.empty())
        return false;
    for (size_t i = 0; i < input.size(); ++i) {
        if (!isprint(input[i])) {
            return (false);
        }
    }
    return true;
}

std::string Contact::getValidInput(const std::string &prompt)
{
    std::string input;

    std::cout << prompt << " : ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit (0);
    while (!isValidInput(input) ||
        (prompt == "Phone number" && input.find_first_not_of("0123456789") < input.size()))
    {
        std::cout << prompt << " (try again) : ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit (0);
    }
    return input;
}
void Contact::setInfo()
{
    firstName = getValidInput("First name");
    lastName = getValidInput("Last name");
    nickname = getValidInput("Nickname");
    phoneNumber = getValidInput("Phone number");
    darkestSecret = getValidInput("Darkest secret");
}

std::string Contact::formatDisplay(const std::string &str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ('.'));
    else
        return (std::string(10 - str.size(), ' ') + str);
}

void Contact::displayBrief(const int index)
{
    std::cout << "|" << std::setw(10) << index
              << "|" << formatDisplay(firstName)
              << "|" << formatDisplay(lastName)
              << "|" << formatDisplay(nickname)
              << "|" << std::endl;
}
void    Contact::displayall()
{
    std::cout << "first name : " << firstName << std::endl;
    std::cout << "last name : " << lastName << std::endl;
    std::cout << "nick name : " << nickname << std::endl;
    std::cout << "phone number  : " << phoneNumber << std::endl;
    std::cout << "darkest secret  : " << darkestSecret << std::endl;
}