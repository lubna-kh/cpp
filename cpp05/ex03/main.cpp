#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        // Create bureaucrats
        Bureaucrat bob("Bob", 150);       // low rank
        Bureaucrat alice("Alice", 50);    // medium rank
        Bureaucrat charlie("Charlie", 1); // top rank

        // Create forms
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << bob << alice << charlie;
        std::cout << shrub << robot << pardon;

        bob.signForm(shrub);      // should fail
        alice.signForm(robot);    // should succeed
        bob.signForm(pardon);     // should fail
        charlie.signForm(pardon); // should succeed

        // Print status after signing
        std::cout << shrub << robot << pardon;

        // Executing forms
        bob.executeForm(shrub);      // should succeed
        alice.executeForm(robot);    // might succeed or fail robotomy
        charlie.executeForm(pardon); // should succeed

        // Attempt to execute unsigned form
        ShrubberyCreationForm unSignedForm("Garden");
        alice.executeForm(unSignedForm); // should throw exception

    } 
    catch (std::exception &e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
