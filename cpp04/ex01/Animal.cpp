# include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constuctor"<<std::endl;
    type = "Animal";
}

Animal::Animal(const Animal &other)
{
    std::cout<< "Animal Copy Constructor"<<std::endl;
    type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout<< "Animal Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout<<"Animal Destructor Called"<<std::endl;
}

void Animal::makeSound() const
{
    std::cout<<"Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}