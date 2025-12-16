#include "ClapTrap.hpp"

int main()
{
    ClapTrap cat;
    // ClapTrap dog;

    cat = ClapTrap("");

    cat.attack("dog");
    cat.takeDamage(5);
    cat.beRepaired(3);
    cat.attack("dog");
    cat.takeDamage(10);
    cat.beRepaired(5);
    cat.attack("dog");
    cat.takeDamage(3);
    cat.beRepaired(2);
    cat.attack("dog");
    cat.attack("dog");
    cat.attack("dog");
    cat.attack("dog");
    cat.attack("dog");
    return 0;
}