#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "DogCat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "================================== CONSTRUCTORS ==============================" << std::endl;
    std::cout << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* w = new WrongCat();
    
    std::cout << std::endl;
    std::cout << "================================== TESTING MESSAGES ==============================" << std::endl;
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << w->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    w->makeSound();

    std::cout << std::endl;
    std::cout << "================================== DESTRUCTORS ==============================" << std::endl;
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete w;
    
    return 0;
}