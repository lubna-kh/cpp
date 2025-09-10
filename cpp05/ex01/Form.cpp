#include "Form.hpp"

Form::Form() : name("default") , gradeSigned(1), gradeExc(1), isSigned(false)
{
	//what i should initialize the grade and the name?
	std::cout<<"Form Default Constructor\n";
}

Form::Form(const std::string &name, int gradeSigned, int gradeExc) : name(name), gradeSigned(gradeSigned), gradeExc(gradeExc), isSigned(false)
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

Form::~Form()
{
	std::cout<<"Form Default destructor\n";
}

Form::Form(const Form& other) : name(other.name), gradeSigned(other.gradeSigned), gradeExc(other.gradeExc)
{
	std::cout<<"Form Copy Constructor\n";
}

Form &Form::operator=(const Form& other)
{
	std::cout<<"Form Copy Assignment Constructor\n";
	if (this != &other)
	{
		// this->grade = other.grade;
		// this->name = other.name;
	}
	return *this;
}

void Form::beSigned(Bureaucrat obj)
{
    if (obj.getGrade() > this->gradeSigned)
        throw Bureaucrat::GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream& out,const Form &obj)
{
	out << obj.getName()<<", form grade to signit "<< obj.getGradeSigned()<<".\n";
	out << obj.getName()<<", form grade to execute "<< obj.getGradeExc()<<".\n";
	return out;
}