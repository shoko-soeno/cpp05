#include "Bureaucrat.h"

int main() {
    try {
        // Test valid grade
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;

        // Test increment and decrement
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        // Test too high grade
        try {
            Bureaucrat high("High", 0);
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test too low grade
        try {
            Bureaucrat low("Low", 151);
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test grade boundaries
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