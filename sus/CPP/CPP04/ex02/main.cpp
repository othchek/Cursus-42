#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

int main()
{
    Animal* meta[20];
    int index = 0;

    while (index++ < 20)
    {
        if (index < 10)
            meta[index] = new Dog();
        else
            meta[index] = new Cat();
    }
    index = 0;
    while (index++ < 10)
        delete meta[index];
    return (0);
}