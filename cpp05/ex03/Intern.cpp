#include "Intern.hpp"


Intern::Intern()
{
	// std::cout<<"Intern Default Constructor\n";
}

Intern::~Intern()
{
	// std::cout<<"Intern Default destructor\n";
}

Intern::Intern(const Intern& other)
{
	// std::cout<<"Intern Copy Constructor\n";
        *this = other;
}

Intern &Intern::operator=(const Intern& other)
{
	// std::cout<<"Intern Copy Assignment Constructor\n";
        if (this != &other)
        {
                // nothing to assign
        }
	return *this;
}

AForm *Intern::createShrubbery(const std::string &target)
{
        return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
        return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
        return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
        std::string FormName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
        AForm *(*formFun[3])(const std::string &) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

        for (int i = 0; i < 3; i++)
        {
                if (formName == FormName[i])
                {
                        std::cout<<"Intern creates "<<formName<<".\n";
                        return formFun[i](target);
                }
        }
        std::cout<<"Intern cannot create "<<formName<<".\n";
        return NULL;

}