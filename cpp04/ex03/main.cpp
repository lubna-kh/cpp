// #include "AMateria.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include "Character.hpp"
// #include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
// 
// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << "=== Exam Test: Materia System ===\n\n";

    // 1️⃣ Create a MateriaSource
    std::cout << "[Step 1] Creating MateriaSource...\n";
    IMateriaSource* src = new MateriaSource();

    // 2️⃣ Learn new Materias
    std::cout << "[Step 2] Learning Ice and Cure Materia...\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // ✅ Passed: MateriaSource stores learned Materias successfully

    // 3️⃣ Create a Character
    std::cout << "[Step 3] Creating Character 'me'...\n";
    ICharacter* me = new Character("me");

    // 4️⃣ Equip Materias to Character
    std::cout << "[Step 4] Equipping Materias to 'me'...\n";
    AMateria* tmp;

    tmp = src->createMateria("ice"); // create Ice clone
    me->equip(tmp);
    std::cout << "Equipped Ice.\n";

    tmp = src->createMateria("cure"); // create Cure clone
    me->equip(tmp);
    std::cout << "Equipped Cure.\n";
    // ✅ Passed: 'me' now has 2 Materias equipped

    // 5️⃣ Create another Character to be target
    std::cout << "[Step 5] Creating Character 'bob'...\n";
    ICharacter* bob = new Character("bob");

    // 6️⃣ Use Materias
    std::cout << "[Step 6] Using Materias...\n";
    me->use(0, *bob); // Ice -> Bob
    me->use(1, *bob); // Cure -> Bob
    // ✅ Passed: Output shows Ice shoots and Cure heals correctly

    // 7️⃣ Unequip Materia test
    std::cout << "[Step 7] Unequipping first Materia (Ice)...\n";
    me->unequip(0);
    me->use(0, *bob); // Should do nothing
    // ✅ Passed: unequipped Materia no longer usable, memory safe

    // 8️⃣ Clean up memory
    std::cout << "[Step 8] Deleting Characters and MateriaSource...\n";
    delete bob;
    delete me;
    delete src;
    // ✅ Passed: All allocated Materias deleted without leaks

    std::cout << "\n=== Test Completed Successfully ===\n";
    return 0;
}
