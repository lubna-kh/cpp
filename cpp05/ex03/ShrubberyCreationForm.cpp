#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	// std::cout<<"ShrubberyCreationForm Default Constructor\n";
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout<<"ShrubberyCreationForm Default destructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
        // std::cout<<"ShrubberyCreationForm Parametrized Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
	// std::cout<<"ShrubberyCreationForm Copy Constructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	// std::cout<<"ShrubberyCreationForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                this->AForm::operator=(other);
	}
	return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & human) const
{
        if (getIsSigned())
                throw AForm::GradeTooLowException();
        if (human.getGrade() > getGradeExc())
                throw AForm::GradeTooLowException();
        std::ofstream file((target + "_shrubbery").c_str());
        file << "  &&& &&  & &&\n"
     << "&& &\\/&\\|& ()|/ @, &&\n"
     << "&\\/(/&/&||/& /_/)_&/_&\n"
     << "&() &\\/&|()|/&\\/ '%\" & ()\n"
     << "&_\\_&&_\\ |& |&&/&__%_/_& &&\n"
     << "&&   && & &| &| /& & % ()& /&&\n"
     << "()&_---()&\\&\\|&&-&&--%---()~\n"
     << "&&    \\|||\n"
     << "|||\n"
     << "|||\n"
     << "|||\n"
     << "-=-~  .-^- _\n";

        file.close();
        
}
