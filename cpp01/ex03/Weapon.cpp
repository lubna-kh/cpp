#include "Weapon.hpp"

Weapon::Weapon(std:: string type) : type(type) {}

//returning a reference to a string
//that you are not allowed to modify through this reference
const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}