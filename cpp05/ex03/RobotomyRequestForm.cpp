#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	// std::cout<<"RobotomyRequestForm Default Constructor\n";
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout<<"RobotomyRequestForm Default destructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
        // std::cout<<"RobotomyRequestForm Parametrized Constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
	// std::cout<<"RobotomyRequestForm Copy Constructor\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	// std::cout<<"RobotomyRequestForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                this->AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned())
			throw AForm::GradeTooLowException();
	if (executor.getGrade() > getGradeExc())
			throw AForm::GradeTooLowException();
	// Get a different random number each time the program runs
	srand(time(0));

	// Generate a random number between 0 and 100
	int randomNum = rand() % 101;
	if (randomNum >= 50)
	{
		std::cout<<target<<" has been robotomized successfully 50%% of the time.\n";
	}
	else
	{
		std::cout<<target<<" he robotomy failed.\n";
	}
}