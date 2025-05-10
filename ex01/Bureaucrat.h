#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat {
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    ~Bureaucrat();

    const std::string&  getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

/* what() is a virtual function defiend in c++'s std::exception class.
It returns a message that describes what caused the exeption.
When you catch an exception, you can call what() to get a human-readable
error message.
*/

#endif
