#include "AForm.hpp"

AForm::AForm() : name("default") , gradeSigned(1), gradeExc(1), isSigned(false)
{
	//what i should initialize the grade and the name?
	std::cout<<"AForm Default Constructor\n";
}

AForm::AForm(const std::string &name, int gradeSigned, int gradeExc) : name(name), gradeSigned(gradeSigned), gradeExc(gradeExc), isSigned(false)
{
	std::cout<<"Form Parametrized Constructor\n";
	if (gradeSigned > 150 || gradeExc > 150)
		throw GradeTooLowException();//this create a GradeTooHighException object
	if (gradeSigned < 1 || gradeExc < 1)
		throw GradeTooHighException();
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
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form Grade too hight! It should be at least 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form Grade too low! It should be at most 150.";
}

std::ostream &operator<<(std::ostream& out,const AForm &obj)
{
	out << obj.getName()<<", Aform grade to signit "<< obj.getGradeSigned()<<".\n";
	out << obj.getName()<<", Aform grade to execute "<< obj.getGradeExc()<<".\n";
	return out;
}