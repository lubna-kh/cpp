#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

// a reference must refer to something valid at all times
// a pointer can be null
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}


//       ┌──────────────────────┐
//       │ Returned Value        │
//       │ const std::string&    │
//       └──────────┬───────────┘
//                  │
//                  ▼
//   ❌ You cannot modify the string
//      through this returned reference.
//      (Protects the return value)

//       ┌──────────────────────┐
//       │ Function const        │
//       │ ... ) const           │
//       └──────────┬───────────┘
//                  │
//                  ▼
//   ❌ This function promises NOT
//      to change *any* members
//      of the Weapon object.
//      (Protects the object itself)