#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45),
      _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45),
      _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src),
      _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    std::cout << "Drrr... " << _target << " has been robotomized successfully 50% of the time." << std::endl;
}
