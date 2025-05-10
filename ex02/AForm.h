#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.h"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;

public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    virtual ~AForm();

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0;
    void checkExecution(const Bureaucrat& executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
