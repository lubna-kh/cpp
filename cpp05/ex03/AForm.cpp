#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default") , gradeSigned(1), gradeExc(1), isSigned(false)
{
	// std::cout<<"AForm Default Constructor\n";
}

AForm::AForm(const std::string &name, int gradeSigned, int gradeExc) : name(name), gradeSigned(gradeSigned), gradeExc(gradeExc), isSigned(false)
{
	// std::cout<<"Form Parametrized Constructor\n";
	if (gradeSigned > 150 || gradeExc > 150)
		throw GradeTooLowException();//this create a GradeTooHighException object
	if (gradeSigned < 1 || gradeExc < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	// std::cout<<"AForm Default destructor\n";
}

AForm::AForm(const AForm& other) : name(other.name), gradeSigned(other.gradeSigned), gradeExc(other.gradeExc)
{
	// std::cout<<"AForm Copy Constructor\n";
	this->isSigned = other.isSigned;
}

AForm &AForm::operator=(const AForm& other)
{
	// std::cout<<"AForm Copy Assignment Constructor\n";
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat & obj)
{
    if (obj.getGrade() > this->gradeSigned)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form Grade too high!.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form Grade too low!.";
}

const char *AForm::FromNotSignedException::what() const throw()
{
	return "Form has not been signed yet!.";
}

std::ostream &operator<<(std::ostream& out,const AForm &obj)
{

	out<<"Form name: "<<obj.getName()<<"\nForm is signed: "
	<<(obj.getIsSigned() ? "true" : "false")<<"\nGrade required to sign the form: "
	<<obj.getGradeSigned()<<"\nGrade required to execute the form: "
	<<obj.getGradeExc()<<"\n";
	return out;
}

bool	AForm::getIsSigned() const
{
	return	isSigned;
}

int	AForm::getGradeSigned() const
{
	return gradeSigned;
}

int	AForm::getGradeExc() const
{
	return gradeExc;
}

const std::string &AForm::getName() const
{
	return name;
}