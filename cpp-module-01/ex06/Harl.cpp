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

    int priority = 4;
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            priority = i;
            break ;
        }          
    }

    for (int i = priority; i < 4; i++)
    {
        switch(i){
        case 0:
            debug(); break;
        case 1:
            info(); break;
        case 2:
            warning(); break;
        case 3:
            error(); break;
        }
    }
    if (priority > 3)
        std::cout << "[Probably complaining... ]\nSwitch him off.\n";    
}
