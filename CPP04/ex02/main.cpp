#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "DogCat.hpp"
#include "Brain.hpp"

int main()
{
    // Animal a;
    // Animal *animal = new Animal();

    Animal *dog = new Dog();
    Animal *cat = new Cat();

    std::cout << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;
    
    return 0;
}
