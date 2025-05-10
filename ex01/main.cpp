#include "Bureaucrat.h"
#include "Form.h"

int main() {
    try {
        std::cout << "\n-------- Valid Form --------\n";
        Form valid_form("valid form", 50, 30);
        std::cout << valid_form << std::endl;
        std::cout << "\n-------- Too high --------\n";
        try {
            Form form_too_high("too high", 0, 30);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-------- Too low --------\n";
        try {
            Form form_too_low("too low", 50, 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-------- sign success --------\n";
        try {
            Bureaucrat bureaucrat1("bureaucrat1", 50);
            Form form_to_sign("to sign", 50, 30);
            std::cout << "Before signing: "
                  << form_to_sign << std::endl;
            bureaucrat1.signForm(form_to_sign);
            std::cout << "after signing: "
                  << form_to_sign << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "\n-------- sign fail --------\n";
        try {
            Bureaucrat bureaucrat2("bureaucrat2", 100);
            Form form_to_sign_fail("to sign", 20, 10);
            std::cout << "Before signing: "
                  << form_to_sign_fail << std::endl;
            bureaucrat2.signForm(form_to_sign_fail);
            std::cout << "after signing: "
                  << form_to_sign_fail << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
    return 0;
}
