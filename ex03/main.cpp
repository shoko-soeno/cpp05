#include "Bureaucrat.h"
#include "Intern.h"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat boss("Superviser", 1);

        std::cout << "\n----- Test 1: Create and execute Shrubbery Creation Form -----\n";
        {
            AForm *form = intern.makeForm("shrubbery creation", "home");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 2: Create and execute Robotomy Request Form -----\n";
        {
            AForm *form = intern.makeForm("robotomy request", "psychopath");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 3: Create and execute Presidential Pardon Form -----\n";
        {
            AForm *form = intern.makeForm("presidential pardon", "prisoner");
            if (form)
            {
                boss.signForm(*form);
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 4: Try to create an invalid form -----\n";
        {
            try
            {
                AForm *form = intern.makeForm("invalid form", "target");
                if (form)
                    delete form;
            }
            catch (std::exception &e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        std::cout << "\n----- Test 5: Execute without signing -----\n";
        {
            AForm *form = intern.makeForm("shrubbery creation", "garden");
            if (form)
            {
                boss.executeForm(*form);
                delete form;
            }
        }

        std::cout << "\n----- Test 6: Low grade bureaucrat tries to sign -----\n";
        {
            Bureaucrat low("LowBureaucrat", 150);
            AForm *form = intern.makeForm("robotomy request", "target2");
            if (form)
            {
                low.signForm(*form);     // ← グレード不足で署名失敗
                delete form;
            }
        }
        
        std::cout << "\n----- Test 7: Low grade bureaucrat tries to execute -----\n";
        {
            Bureaucrat low("LowBureaucrat", 150);
            AForm *form = intern.makeForm("robotomy request", "target3");
            if (form)
            {
                boss.signForm(*form);    // 署名は上位の boss が行う
                low.executeForm(*form);  // 実行はグレード不足で失敗
                delete form;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
   
    std::cout << "\n----- End of tests -----\n";
    return 0;
}

