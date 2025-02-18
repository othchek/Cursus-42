#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();
    k->makeSound();

    std::cout << "Wrongcat Test" << std::endl;
    std::cout << k->getType() << " " << std::endl;

    delete meta;
    delete j;
    delete i;
    delete k;
}
