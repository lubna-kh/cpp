#include "Bureaucrat.hpp"
#include "AForm.hpp"
Bureaucrat::Bureaucrat() : name("default") , grade(1)
{
	//what i should initialize the grade and the name?
	// std::cout<<"Bureaucrat Default Constructor\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	// std::cout<<"Bureaucrat Parametrized Constructor\n";
	if (grade > 150)
		throw GradeTooLowException();//this will create a GradeTooHighException object
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout<<"Bureaucrat Default destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
	// std::cout<<"Bureaucrat Copy Constructor\n";
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	// std::cout<<"Bureaucrat Copy Assignment Constructor\n";
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

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
	return "Bureaucrat Grade too high!.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Grade too low!.";
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout<<this->getName()<<" signed "<<f.getName()<<'\n';
	}
	catch(const std::exception& e)
	{
		std::cerr <<this->getName()<<" couldn't sign "<<f.getName()<<" because "<<e.what()<<'\n';
	}
	
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout<<this->getName()<<" executed "<<form.getName()<<'\n';
	}
	catch(const std::exception& e)
	{
		std::cerr <<this->getName()<<" couldn't execute "<<form.getName()<<" because "<<e.what()<<'\n';
	}
	
}

std::ostream &operator<<(std::ostream& out,const Bureaucrat &obj)
{
	out << obj.getName()<<", bureaucrat grade "<< obj.getGrade()<<".\n";
	return out;
}