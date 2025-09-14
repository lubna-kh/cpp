#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        const int gradeSigned;
        const int gradeExc;
        bool isSigned;
    public:
        AForm();
		AForm(const std::string& name, int gradeSigned, int gradeExc);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

        bool	getIsSigned() const;
        int	getGradeSigned() const;
        int	getGradeExc() const;
		const std::string &getName() const;

        void beSigned(const Bureaucrat & obj);

        class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};

        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream& out,const AForm &obj);

#endif