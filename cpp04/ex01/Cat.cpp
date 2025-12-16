# include "Cat.hpp"

Cat::Cat()
{
    std::cout<< "Cat Default Constructor"<<std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout<< "Cat Copy Constructor"<<std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout<< "Cat Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);//this will call the brain copy constructor
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout<<"Cat Sound" << std::endl;
}

Cat::~Cat()
{
    std::cout<< "Cat Destructor Called"<<std::endl;
    delete brain;
}