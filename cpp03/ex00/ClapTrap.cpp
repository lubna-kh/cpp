#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap Default Constructor Called" <<std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name.size() == 0 ? "Default" : Name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<< "ClapTrap Parametrized constructor Called" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout<< "ClapTrap Copy constructor Called" <<std::endl;
	Name = other.Name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout<<"ClapTrap Copy Assignment Constructor Called" << std::endl;
	if (this != &other)
	{
		Name = other.Name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout<< "ClapTrap Destructor Called"<< std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (target.size() == 0)
	{
		std::cout<< "ClapTrap " << Name << " cannot attack an empty target!" << std::endl;
		return ;
	}
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout<<"ClapTrap " << Name << " can not attack because it has no energy left or hit points!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout<< "ClapTrap " << Name << " attacks " << target<< ", causing "
		<< attackDamage <<" points of damage!" <<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << Name << " has no energy left to be repaired!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << Name << " has been repaired by " << amount
			  << " points, now has " << hitPoints << " hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
	{
		hitPoints = 0;
		std::cout << "ClapTrap "<< Name << " has lost his all hitPoints!" << std::endl;
	}
	else
	{
		hitPoints -= amount;
		std::cout<< "ClapTrap " << Name << " has lost " << amount << "  HitPoints" <<std::endl;
	}
}