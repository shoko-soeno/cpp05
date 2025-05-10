#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137),
      _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137),
      _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src),
      _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile.is_open())
        throw FileOpenException();

    outFile << "  *" << std::endl;
    outFile << " ***" << std::endl;
    outFile << "*****" << std::endl;
    outFile << "  |" << std::endl;

    outFile.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Failed to open file";
}
