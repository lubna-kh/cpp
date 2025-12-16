#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(),ScavTrap()
{
	std::cout<< "DiamodTrap default Constructor" <<std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout<< "DiamodTrap Parametrized Constructor" <<std::endl;
	this->Name = name;
	ClapTrap::Name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other), ScavTrap(other)
{
	std::cout<< "DiamodTrap Copy Constructor"<<std::endl;
	this->Name = other.Name;
	this->energyPoints = other.energyPoints;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout<< "DiamondTrap Copy Assignmnet Opertor Constructor"<<std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout<< "DiamodTrap default Destructor"<<std::endl;

}

void DiamondTrap::whoAmI()
{
	std::cout<< "DiamondTrap name is "<<Name<<" , and ClapTrap name is "<< ClapTrap::Name <<std::endl;
}

void	DiamondTrap::attack()
{
	ScavTrap::attack(this->Name);
}