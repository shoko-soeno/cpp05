#include "AForm.h"

AForm::AForm()
    : _name("Default"),
      _isSigned(false),
      _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute) {}

AForm &AForm::operator=(const AForm& src)
{
    if (this != &src)
        _isSigned = src._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form must be signed before execution";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName()
       << "\n Status: " << (form.getIsSigned() ? "signed" : "not signed")
       << "\n Grade to sign: " << form.getGradeToSign()
       << "\n Grade to execute: " << form.getGradeToExecute();
    return os;
}
