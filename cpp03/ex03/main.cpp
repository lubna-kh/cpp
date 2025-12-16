#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    DiamondTrap d("lubna");
    d.FragTrap::attack("an");
    d.ScavTrap::attack("an");
    return 0;
}
//energy:7
//hitpoint:8
//attackDamage:0
