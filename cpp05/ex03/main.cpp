#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 150);

        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (shrub)
        {
            bob.signForm(*shrub);
            bob.executeForm(*shrub);
            delete shrub;
        }

        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        AForm* robo = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robo)
        {
            bob.signForm(*robo);
            bob.executeForm(*robo);
            delete robo;
        }

        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        if (pardon)
        {
            bob.signForm(*pardon);
            bob.executeForm(*pardon);
            delete pardon;
        }

        std::cout << "\n--- Testing Invalid Form ---\n";
        AForm* wrong = someRandomIntern.makeForm("coffee request", "Alice");
        if (wrong)
            delete wrong;
            // std::cout << "Intern couldn’t create the form: coffee request\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
