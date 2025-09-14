#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{
	//what i should initialize the grade and the name?
	std::cout<<"PresidentialPardonForm Default Constructor\n";
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm Default destructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 145, 137)
{
        std::cout<<"PresidentialPardonForm Parametrized Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	std::cout<<"PresidentialPardonForm Copy Constructor\n";
	// this->grade = other.grade;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout<<"PresidentialPardonForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                this->AForm::operator=(other);
	}
	return *this;
}