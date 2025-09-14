#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>
class RobotomyRequestForm : public AForm
{
        private:
                const std::string target;
        public:
                RobotomyRequestForm();
                RobotomyRequestForm(const std::string& target);
                RobotomyRequestForm(const RobotomyRequestForm& other);
                RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
                ~RobotomyRequestForm();

                void execute(Bureaucrat const & executor) const;
};

#endif