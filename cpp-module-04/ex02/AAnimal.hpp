#ifndef AAnimal_HPP
#define AAnimal_HPP


#include <iostream>
#include <string>

class AAnimal{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(const AAnimal& copy);
        AAnimal &operator=(const AAnimal& other);
        virtual ~AAnimal();

        std::string getType() const;
        virtual void makeSound() const = 0;
};










#endif