#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	this->Name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "FragTrap Parametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	this->Name = other.Name;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->hitPoints = other.hitPoints;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy Assignment Constructor Called" << std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		this->hitPoints = other.hitPoints;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<< "FragTrap Destrutor Called"<< std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap "<< this->Name << " is requesting a high five! ✋" << std::endl;
}

