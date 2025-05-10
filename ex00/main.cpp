#include "Bureaucrat.h"

int main() {
    try {
        std::cout << "\n-------- Valid grade --------\n";
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        std::cout << "\n-------- Test increment and decrement --------\n";
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        std::cout << "\n-------- Test too high --------\n";
        try {
            Bureaucrat high("High", 0);
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test too low--------\n";
        try {
            Bureaucrat low("Low", 151);
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "\n-------- Test edge cases--------\n";
        Bureaucrat top("Top", 1);
        try {
            top.incrementGrade();
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        Bureaucrat bottom("Bottom", 150);
        try {
            bottom.decrementGrade();
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
