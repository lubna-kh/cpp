#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	//what i should initialize the grade and the name?
	std::cout<<"ShrubberyCreationForm Default Constructor\n";
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm Default destructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137)
{
        std::cout<<"ShrubberyCreationForm Parametrized Constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	std::cout<<"ShrubberyCreationForm Copy Constructor\n";
	// this->grade = other.grade;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout<<"ShrubberyCreationForm Copy Assignment Constructor\n";
	if (this != &other)
	{
                this->AForm::operator=(other);
	}
	return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & human) const
{
        if (human.getGrade() > 145)
                throw AForm::GradeTooLowException();
        if (human.getGrade() > 137)
                throw AForm::GradeTooLowException();
        std::ofstream file(this->getName() + "_shrubbery");
        file << R"(            
        &&& &&  & &&
      && &\/&\|& ()|/ @, &&
      &\/(/&/&||/& /_/)_&/_&
   &() &\/&|()|/&\/ '%" & ()
  &_\_&&_\ |& |&&/&__%_/_& &&
&&   && & &| &| /& & % ()& /&&
 ()&_---()&\&\|&&-&&--%---()~
     &&     \|||
             |||
             |||
             |||
       , -=-~  .-^- _
)";

        file.close();
        
}
