#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default") , gradeSigned(1), gradeExc(1)
{
	// std::cout<<"Form Default Constructor\n";
	isSigned = false;
}

Form::Form(const std::string &name, int gradeSigned, int gradeExc) : name(name), gradeSigned(gradeSigned), gradeExc(gradeExc)
{
	// std::cout<<"Form Parametrized Constructor\n";
	if (gradeSigned > 150 || gradeExc > 150)
		throw GradeTooLowException();//this create a GradeTooHighException object
	if (gradeSigned < 1 || gradeExc < 1)
		throw GradeTooHighException();
	isSigned = false;
}

Form::~Form()
{
	// std::cout<<"Form Default destructor\n";
}

Form::Form(const Form& other) : name(other.name), gradeSigned(other.gradeSigned), gradeExc(other.gradeExc)
{
	// std::cout<<"Form Copy Constructor\n";
	this->isSigned = other.isSigned;
}

Form &Form::operator=(const Form& other)
{
	// std::cout<<"Form Copy Assignment Constructor\n";
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->gradeSigned)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade too high!.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low!.";
}

std::ostream &operator<<(std::ostream& out,const Form &obj)
{

	out<<"Form name: "<<obj.getName()<<"\nForm is signed: "
	<<(obj.getIsSigned() ? "true" : "false")<<"\nGrade required to sign the form: "
	<<obj.getGradeSigned()<<"\nGrade required to execute the form: "
	<<obj.getGradeExc()<<"\n";
	return out;
}

bool	Form::getIsSigned() const
{
	return	isSigned;
}
int	Form::getGradeSigned() const
{
	return gradeSigned;
}
int	Form::getGradeExc() const
{
	return gradeExc;
}
const std::string &Form::getName() const
{
	return name;
}