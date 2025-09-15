#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);

        Form formA("FormA", 45, 30);
        Form formB("FormB", 60, 20);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        bob.signForm(formA);
        alice.signForm(formA);
        bob.signForm(formB);

        std::cout <<std::endl<< formA << std::endl;
        std::cout << formB << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
