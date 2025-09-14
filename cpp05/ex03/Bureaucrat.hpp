#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
class AForm;
class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		int	getGrade() const;
		void	decrementGrade();
		void	incrementGrade();
		const std::string &getName() const;

		void signForm(AForm &f);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};


std::ostream &operator<<(std::ostream& out,const Bureaucrat &obj);

#endif