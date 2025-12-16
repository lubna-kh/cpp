#include "Dog.hpp"

Dog::Dog()
{
    std::cout<< "Dog Default Constructor"<<std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout<< "Dog Copy Constructor"<<std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout<< "Dog Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout<< "Dog Sound"<<std::endl;
}

Dog::~Dog()
{
    std::cout<< "Dog Destructor Called"<<std::endl;
}