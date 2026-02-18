#include <iostream>

// class test
// {
//     public:
//         test(){
//             std::cout << "constructor called" << std::endl;
//         };
//         ~test(){
//             std::cout << "Destructor called" << std::endl;
//         };
// };


// void func2(){
//     test t1;
//     std::cout << "Func 2 Called" << std::endl;
//     throw 0;
// }

// void func1(){
//     std::cout << "Func 1 Called" << std::endl;
//     func2();
//     return ;
// }

// int main(){
//     try
//     {
//         func1();
//     }
//     catch(std::string x)
//     {
//         std::cerr << "Exception Thrown" << '\n';
//     }
//     catch (...){
//         std::cerr << "Exception Catched" << '\n';
//     }
    
//     std::cout << "Program Continue ..." << std::endl;
//     return 0;
// }

class Animal
{
    protected:
        std::string name;
    public:
        Animal(std::string n) : name(n){
            std::cout << "Constructor Called" << std::endl;
        };

        virtual void makeSound(){
            std::cout << this->name << " make a sound " << std::endl;
        }

        virtual ~Animal(){
            std::cout << "Destructor called" << std::endl;
    };
};

class Dog : public Animal
{
    private:
        std::string breed;
    public:
        Dog(std::string n, std::string b) : Animal(n), breed(b){
            std::cout << "Dog Constructor Called" << std::endl;
        };

        void makeSound(){
            std::cout << name << " Woof ! " << std::endl;
        }

        void fetch(){
            std::cout << name << " (" << breed << ") " << "is fetching!" << std::endl;
        }

        ~Dog(){
            std::cout << "Dog Destructor Called" << std::endl;
        };
};

int main(){
    Dog myDog("Kliyeb", "Kanich");

    Animal &myAnimal = myDog;

    myDog.makeSound();
    std::cout << std::endl;

    myAnimal.makeSound();
    std::cout << std::endl;

    Dog dog = static_cast<Dog&>(myAnimal);
    dog.fetch();
}
