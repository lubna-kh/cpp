#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	this->Name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Parametrized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	this->Name = other.Name;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	this->hitPoints = other.hitPoints;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy Assignment Constructor Called" << std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		this->hitPoints = other.hitPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<< "ScavTrap Destrutor Called"<< std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ScaveTrap " << this->Name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScaveTrap "<<this->Name<<" has no energy or hit points left to attack."<<std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate Keeping Mode" << std::endl;
}

