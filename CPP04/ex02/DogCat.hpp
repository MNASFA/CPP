#ifndef DOGCAT_HPP
#define DOGCAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
        Brain *getBrain(void) const;
};

class Cat : public Animal
{
        private:
            Brain *brain;
        public:
            Cat();
            Cat(const Cat &other);
            Cat &operator=(const Cat &other);
            ~Cat();

            void makeSound() const;
            Brain *getBrain(void) const;
};

#endif