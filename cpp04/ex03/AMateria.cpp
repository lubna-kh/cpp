#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout<<"AMateria Default Constructor\n";
}

AMateria::AMateria(std::string const &type)
{
    std::cout<<"AMateria Default Constructor\n";
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout<<"AMateria Copy Constructor\n";
    this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout<<"AMateria Copy Assignmet Constructor\n";
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    if (type == "ice")
        std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *\n";
    else if (type == "cure")
        std::cout<<"* heals "<<target.getName()<<"'s wounds *\n";
}

AMateria::~AMateria()
{
    std::cout<<"AMateria Default destructor\n";
}