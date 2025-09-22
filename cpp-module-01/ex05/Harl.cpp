#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ] Some debug message\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ] Some info message\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ] Some warning message\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ] Some error message\n";
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])(void) = {
        &Harl::debug,
        &Harl::error,
        &Harl::info,
        &Harl::warning
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
        else if (i == 3)
            std::cerr << "Error not found" << std::endl;
    }
}