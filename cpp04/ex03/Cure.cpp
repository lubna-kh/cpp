#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout<<"Cure Default Constructor\n";
    type = "cure";
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout<<"Cure Copy Constructor\n";
    // this->type = other.type; //no need because AMateria(other) already copied it
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout<<"Cure Copy Assignmet Constructor\n";
    if (this != &other)
    {
        this->type = other.type;
        // AMateria::operator=(other); //this ensures any future changes in AMateria are properly copied(like if i have another attributes)
    }
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &other)
{
    std::cout<<"* heals "<<other.getName()<<"'s wounds *\n";
}

Cure::~Cure()
{
    std::cout<<"Cure Default destructor\n";
}