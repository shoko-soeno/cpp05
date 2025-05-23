#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
    try
    {
        Bureaucrat highGrade("HighGrade", 1);
        Bureaucrat midGrade("MidGrade", 50);
        Bureaucrat lowGrade("LowGrade", 150);

        std::cout << "\n-------- Test ShrubberyCreationForm --------\n";
        {
            ShrubberyCreationForm shrub("tree");
            std::cout << shrub << std::endl;

            std::cout << "\nTesting with low grade bureaucrat:\n";
            lowGrade.signForm(shrub);
            lowGrade.executeForm(shrub);

            std::cout << "\nTesting with mid grade bureaucrat:\n";
            midGrade.signForm(shrub);
            midGrade.executeForm(shrub);

            std::cout << "\nAfter signing with mid grade bureaucrat:\n";
            std::cout << shrub << std::endl;
        }

        std::cout << "\n-------- Test RobotomyRequestForm --------\n";
        {
            RobotomyRequestForm robotomy("Target1");
            std::cout << robotomy << std::endl;

            std::cout << "\nTesting with mid grade bureaucrat:\n";
            midGrade.signForm(robotomy);
            midGrade.executeForm(robotomy);

            std::cout << "\nTesting with high grade bureaucrat:\n";
            highGrade.executeForm(robotomy);
        }

        std::cout << "\n-------- Test PresidentialPardonForm --------\n";
        {
            PresidentialPardonForm pardon("Criminal1");
            std::cout << pardon << std::endl;

            std::cout << "\nTesting execution without signature:\n";
            highGrade.executeForm(pardon);

            std::cout << "\nTesting complete process with high grade bureaucrat:\n";
            highGrade.signForm(pardon);
            highGrade.executeForm(pardon);

            std::cout << "\nAfter signing with high grade bureaucrat:\n";
            std::cout << pardon << std::endl;
        }

        std::cout << "\n-------- Test Invalid Grade Creation --------\n";
        try
        {
            Bureaucrat tooHigh("TooHigh", 0);
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat tooLow("TooLow", 151);
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "\n----- End of tests -----\n";
    return 0;
}
