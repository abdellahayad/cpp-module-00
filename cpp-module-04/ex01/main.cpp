#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
// #include <string>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();
    
    delete j;
    delete i;

    std::cout << "\n--- Array test ---" << std::endl;
    Animal* animals[4];

    for (int k = 0; k < 4; k++) {
        if (k < 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    for (int k = 0; k < 4; k++)
        delete animals[k];

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Dog dog1;

    dog1.getBrain()->setIdea(0, "i need to sleep");
    Dog dog2 = dog1;

    std::cout << "dog1 idea" << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea" << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "i need to eat");

    std::cout << "dog1 idea" << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea" << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}