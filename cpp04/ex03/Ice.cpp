#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout<<"Ice Default Constructor\n";
    type = "ice";
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout<<"Ice Copy Constructor\n";
    // this->type = other.type;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout<<"Ice Copy Assignmet Constructor\n";
    if (this != &other)
    {
        this->type = other.type;
        // AMateria::operator=(other); //this ensures any future changes in AMateria are properly copied(like if i have another attributes)
    }
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &other)
{
    std::cout<<"* shoots an ice bolt at "<<other.getName()<<" *\n";
}

Ice::~Ice()
{
    std::cout<<"Ice Default destructor\n";
}