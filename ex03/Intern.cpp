#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    *this = src;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    int j = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            j = i;
            break;
        }
    }

    AForm* form = NULL;
    switch (j) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw FormNotFoundException();
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Error: Form name is invalid.";
}
