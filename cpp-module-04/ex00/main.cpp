#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <string>

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "================================================" << std::endl;

    const WrongAnimal *wrong = new WrongCat();
    std::cout << wrong->getType() << std::endl;
    wrong->makeSound();

    delete j;
    delete i;
    delete meta;
    delete wrong;

    return 0;
}