#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	//what i should initialize the grade and the name?
	std::cout<<"RobotomyRequestForm Default Constructor\n";
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm Default destructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 145, 137)
{
        std::cout<<"RobotomyRequestForm Parametrized Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	std::cout<<"RobotomyRequestForm Copy Constructor\n";
	// this->grade = other.grade;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout<<"RobotomyRequestForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                this->AForm::operator=(other);
	}
	return *this;
}