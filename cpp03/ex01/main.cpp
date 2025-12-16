#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap cat = ScavTrap("ScavClap");
    ClapTrap *catt = new ScavTrap("scav");
    // cat = ScavTrap("ScavClap");
    // cat.attack("dog");
    catt->attack("dogg");
    ScavTrap scav("scav");
    scav.attack("cat");
    scav.guardGate();
    scav.takeDamage(2);
    scav.beRepaired(1);
    scav.takeDamage(8);
    scav.beRepaired(1);
    scav.attack("cat");
    delete catt;
    return 0;
}