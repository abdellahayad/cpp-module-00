#ifndef PRESIDENTIALPARDONFORH_HPP
#define PRESIDENTIALPARDONFORH_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const &executor) const;
};

#endif
