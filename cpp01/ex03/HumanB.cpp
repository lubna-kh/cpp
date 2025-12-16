#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack() const
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with their fists" << std::endl;
}