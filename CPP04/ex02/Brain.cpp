#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called !" << std::endl;
    for (int i = 0; i < 100 ; i++)
        this->ideas[i] = "";
}

Brain::Brain(const Brain &other){
    std::cout << "Brain Copy constructor called !" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain::~Brain(){
    std::cout << "Brain Destructor called !" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
    std::cout << "Brain copy assignement operator called !" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

//  Setters and Getters

const std::string &Brain::getIdea(int index) const{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return this->ideas[0];
}

void Brain::setIdea(int index, const std::string &idea){
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}