#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    FragTrap Frag("Frag");
    ScavTrap scav("Scav");

    scav.attack("dog");
    Frag.attack("cat");
    // Frag.ClapTrap::attack("cat");
    return 0;
}
