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
        //add the exception classes here
        bool	getIsSigned() const;
        const int	getGradeSigned() const;
        const int	getGradeExc() const;
		const std::string &getName() const;

        void beSigned(Bureaucrat obj);



};

std::ostream &operator<<(std::ostream& out,const Form &obj);

#endif