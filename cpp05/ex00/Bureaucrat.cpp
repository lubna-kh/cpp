#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") , grade(1)
{
	//what i should initialize the grade and the name?
	std::cout<<"Bureaucrat Default Constructor\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	std::cout<<"Bureaucrat Parametrized Constructor\n";
	if (grade > 150)
		throw GradeTooLowException();//this create a GradeTooHighException object
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat Default destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	std::cout<<"Bureaucrat Copy Constructor\n";
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout<<"Bureaucrat Copy Assignment Constructor\n";
	if (this != &other)
	{
		this->grade = other.grade;
		// this->name = other.name;
	}
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}
/*
what happen when its throw?
1	throw GradeTooHighException() creates exception object
2	Stack unwinding: local objects destroyed
3	Catch block finds a matching catch (const std::exception& e)
4	Exception object is bound to e
5	e.what() is called → returns error string
6	Catch block finishes → exception object destroyed
*/

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Grade too hight! It should be at least 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low! It should be at most 150.";
}

std::ostream &operator<<(std::ostream& out,const Bureaucrat &obj)
{
	out << obj.getName()<<", bureaucrat grade "<< obj.getGrade()<<".\n";
	return out;
}