#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "DogCat.hpp"
#include "Brain.hpp"

// int main()
// {
//     std::cout << "================================== CONSTRUCTORS ==============================" << std::endl;
//     std::cout << std::endl;

//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();
    
//     std::cout << std::endl;
//     std::cout << "================================== TESTING MESSAGES ==============================" << std::endl;
//     std::cout << std::endl;

//     dog->getBrain()->setIdea(3, "Brain 1");
//     cat->getBrain()->setIdea(5, "Brain 2");

//     std::cout << std::endl;
//     std::cout << "================================== Dogs Ideas ==============================" << std::endl;
//     std::cout << std::endl;
    
//     std::cout << "Dog idea : " << dog->getBrain()->getIdea(3) << std::endl;
//     std::cout << "Cat idea : " << cat->getBrain()->getIdea(5) << std::endl;

//     std::cout << "Dog Brain Adress : " << dog->getBrain() << std::endl;
//     std::cout << "Cat Brain Adress : " << cat->getBrain() << std::endl;

//     dog->makeSound();
//     cat->makeSound();

//     std::cout << std::endl;
//     std::cout << "================================== Testing copy constructors ==============================" << std::endl;
//     std::cout << std::endl;

//     const Dog *dog1 = new Dog();
//     dog1->getBrain()->setIdea(10, "First idea");
//     dog1->getBrain()->setIdea(0, "Second Idea");   
//     dog1->getBrain()->setIdea(99, "Last idea");  

//     std::cout << std::endl;
//     std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
//     std::cout << "dog1 idea[10]: " << dog1->getBrain()->getIdea(10) << std::endl;
//     std::cout << "dog1 idea[99]: " << dog1->getBrain()->getIdea(99) << std::endl;
//     std::cout << std::endl;
    
//     const Dog *dog2 = new Dog(*dog1);

//     std::cout << std::endl;
//     std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
//     std::cout << "dog2 idea[10]: " << dog2->getBrain()->getIdea(10) << std::endl;
//     dog2->getBrain()->setIdea(99, "Updated Idea !! ");  
//     std::cout << "dog2 idea[99]: " << dog2->getBrain()->getIdea(99) << std::endl;

//     std::cout << std::endl;
//     std::cout << "================================== DESTRUCTORS ==============================" << std::endl;
//     std::cout << std::endl;

//     delete dog;
//     delete cat;
//     delete dog1;
//     delete dog2;
    
//     return 0;
// }

int main()
{
    std::cout << "============================= Array Of Animals =========================" << std::endl;
    int size = 10;
    Animal *animals[size];

    std::cout << "============================= Dogs Half =========================" << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < size / 2; i++){
        animals[i] = new Dog();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "============================= Cats Half =========================" << std::endl;
    std::cout << std::endl;
    
    for(int i = size / 2; i < size; i++){
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "============================= Testing Animals =========================" << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < size ; i++){
        std::cout << "Animal["<< i << "] : ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < size ; i++){
        if (i < size / 2)
        {
            for (int j = 0; j < 100; j++)
                animals[i]->getBrain()->setIdea(j,"I'm a dog and i will eat !!!");
        }
        else
        {
            for (int j = 0; j < 100; j++)
                animals[i]->getBrain()->setIdea(j,"I'm a cat and i will sleep !!!");
        }
    }
    std::cout << std::endl;
    std::cout << "Dog idea[10]: " << animals[0]->getBrain()->getIdea(10) << std::endl;
    std::cout << "Cat idea[99]: " << animals[8]->getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "================================== Testing copy constructors ==============================" << std::endl;
    std::cout << std::endl;

    const Dog *dog1 = new Dog();
    dog1->getBrain()->setIdea(10, "First idea");
    dog1->getBrain()->setIdea(0, "Second Idea");
    dog1->getBrain()->setIdea(99, "Last idea");
    
    std::cout << std::endl;
    std::cout << "dog1 idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog1 idea[10]: " << dog1->getBrain()->getIdea(10) << std::endl;
    std::cout << "dog1 idea[99]: " << dog1->getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;
    
    const Dog *dog2 = new Dog(*dog1);
    std::cout << std::endl;
    std::cout << "dog2 idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[10]: " << dog2->getBrain()->getIdea(10) << std::endl;
    dog2->getBrain()->setIdea(99, "Updated Idea !! ");  
    std::cout << "dog2 idea[99]: " << dog2->getBrain()->getIdea(99) << std::endl;


    std::cout << std::endl;
    std::cout << "=========================== Destructors (Delete all animals) =========================" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++){
        delete animals[i];
        std::cout << std::endl;
    }

    delete dog1;
    std::cout << std::endl;
    delete dog2;

    return (0);
}