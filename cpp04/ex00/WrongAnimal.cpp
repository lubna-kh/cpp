# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default Constuctor"<<std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout<< "WrongAnimal Copy Constructor"<<std::endl;
    type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout<< "WrongAnimal Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal Destructor Called"<<std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}