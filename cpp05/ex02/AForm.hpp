#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSigned;
        const int gradeExc;
    public:
        AForm();
		AForm(const std::string& name, int gradeSigned, int gradeExc);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		~AForm();
        //add the exception classes here
        bool	getIsSigned() const;
        const int	getGradeSigned() const;
        const int	getGradeExc() const;
		const std::string &getName() const;

        void beSigned(Bureaucrat obj);



};

std::ostream &operator<<(std::ostream& out,const Form &obj);

#endif