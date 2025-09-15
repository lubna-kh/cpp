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
        ShrubberyCreationForm shrub("Home"); //sign=145, exec=134
        RobotomyRequestForm robot("Bender");//sign=72, exec=45
        PresidentialPardonForm pardon("Marvin");//sign=25, exec=5

        std::cout << bob << alice << charlie;
        std::cout << shrub << robot << pardon;

        bob.signForm(shrub);      // should fail
        alice.signForm(robot);    // should succeed
        bob.signForm(pardon);     // should fail
        charlie.signForm(pardon); // should succeed

        // Print status after signing
        std::cout << shrub << robot << pardon;

        // Executing forms
        bob.executeForm(shrub);      // should fail
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
