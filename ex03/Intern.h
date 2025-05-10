#ifndef INTERN_H
# define INTERN_H
# include "AForm.h"
# include "Bureaucrat.h"
# include "RobotomyRequestForm.h"
# include "PresidentialPardonForm.h"
# include "ShrubberyCreationForm.h"

class Intern
{
public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& src);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
