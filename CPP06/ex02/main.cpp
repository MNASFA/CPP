#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(){
    std::srand(time(NULL));
    
    std::cout << "=== Generate a random base object and identify it ====" << std::endl;
    Base *obj = generate();
    std::cout << "=== Identify Pointer ===" << std::endl;
    identify(obj);
    std::cout << "=== Identify Reference ===" << std::endl;
    identify(*obj);

    delete obj;
}
