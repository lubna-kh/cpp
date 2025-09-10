#include "AForm.hpp"

AForm::AForm() : name("default") , gradeSigned(1), gradeExc(1), isSigned(false)
{
	//what i should initialize the grade and the name?
	std::cout<<"AForm Default Constructor\n";
}

AForm::AForm(const std::string &name, int gradeSigned, int gradeExc) : name(name), gradeSigned(gradeSigned), gradeExc(gradeExc), isSigned(false)
{
	std::cout<<"Form Parametrized Constructor\n";
	if (gradeSigned > 150)
		throw Bureaucrat::GradeTooLowException();//this create a GradeTooHighException object
	if (gradeSigned < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeExc > 150)
		throw Bureaucrat::GradeTooLowException();//this create a GradeTooHighException object
	if (gradeExc < 1)
		throw Bureaucrat::GradeTooHighException();
}

AForm::~AForm()
{
	std::cout<<"AForm Default destructor\n";
}

AForm::AForm(const AForm& other) : name(other.name), gradeSigned(other.gradeSigned), gradeExc(other.gradeExc)
{
	std::cout<<"AForm Copy Constructor\n";
}

AForm &AForm::operator=(const AForm& other)
{
	std::cout<<"AForm Copy Assignment Constructor\n";
	if (this != &other)
	{
		// this->grade = other.grade;
		// this->name = other.name;
	}
	return *this;
}

void AForm::beSigned(Bureaucrat obj)
{
    if (obj.getGrade() > this->gradeSigned)
        throw Bureaucrat::GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream& out,const AForm &obj)
{
	out << obj.getName()<<", Aform grade to signit "<< obj.getGradeSigned()<<".\n";
	out << obj.getName()<<", Aform grade to execute "<< obj.getGradeExc()<<".\n";
	return out;
}