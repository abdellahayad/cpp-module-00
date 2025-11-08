#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>


class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(const std::string& t);
        ~ShrubberyCreationForm();
        
        void execute(Bureaucrat const &executor) const;
};




#endif