#include <iostream>

class test
{
    public:
        test(){
            std::cout << "constructor called" << std::endl;
        };
        ~test(){
            std::cout << "Destructor called" << std::endl;
        };
};


void func2(){
    test t1;
    std::cout << "Func 2 Called" << std::endl;
    throw 0;
}

void func1(){
    std::cout << "Func 1 Called" << std::endl;
    func2();
    return ;
}

int main(){
    try
    {
        func1();
    }
    catch(std::string x)
    {
        std::cerr << "Exception Thrown" << '\n';
    }
    catch (...){
        std::cerr << "Exception Catched" << '\n';
    }
    
    std::cout << "Program Continue ..." << std::endl;
    return 0;
}
