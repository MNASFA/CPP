
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main(){
    // AForm form("test", 50 , 25); // Abstarct class cannot instantiate

    Bureaucrat houssam("Houssam", 50);
    std::cout << houssam << std::endl;

    return 0;
}
