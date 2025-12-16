#include "Intern.hpp"

int main(){
    Intern someRandomIntern;

    std::cout << "==================== Test 1 : robotomy request ===============" << std::endl;
    std::cout << std::endl;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
        std::cout << *rrf << std::endl;

    delete rrf;

    std::cout << std::endl;
    std::cout << "==================== Test 2 : shrubbery creation ===============" << std::endl;
    std::cout << std::endl;
    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    if (scf)
        std::cout << *scf << std::endl;

    delete scf;

    std::cout << std::endl;
    std::cout << "==================== Test 3 : presidential pardon ===============" << std::endl;
    std::cout << std::endl;
    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (ppf)
        std::cout << *ppf << std::endl;

    delete ppf;

    return 0;
}
