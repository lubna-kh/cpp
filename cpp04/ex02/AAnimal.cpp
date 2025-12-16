# include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal Default Constuctor"<<std::endl;
    type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout<< "AAnimal Copy Constructor"<<std::endl;
    type = other.type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout<< "AAnimal Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal Destructor Called"<<std::endl;
}

std::string AAnimal::getType() const
{
    return (type);
}