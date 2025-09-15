#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	// std::cout<<"PresidentialPardonForm Default Constructor\n";
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout<<"PresidentialPardonForm Default destructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
        // std::cout<<"PresidentialPardonForm Parametrized Constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	// std::cout<<"PresidentialPardonForm Copy Constructor\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// std::cout<<"PresidentialPardonForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
			throw AForm::FromNotSignedException();
	if (executor.getGrade() > getGradeExc())
			throw Bureaucrat::GradeTooLowException();
	std::cout<< target <<" has been pardoned by Zaphod Beeblebrox.\n";
}