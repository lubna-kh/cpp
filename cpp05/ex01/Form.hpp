#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSigned;
        const int gradeExc;
    public:
        Form();
		Form(const std::string& name, int gradeSigned, int gradeExc);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

        bool	getIsSigned() const;
        int	getGradeSigned() const;
        int	getGradeExc() const;
		const std::string &getName() const;

        void beSigned(const Bureaucrat &obj);

        class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out,const Form &obj);

#endif