#ifndef SHUBBERYCREATIONFORM_H
# define SHUBBERYCREATIONFORM_H
# include "AForm.h"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat& executor) const;

    class FileOpenException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
