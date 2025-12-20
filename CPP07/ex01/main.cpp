#include "iter.hpp"
#include "iostream"

void printInt(const int &n) {
    std::cout << n << " ";
}

void increment(int &n){
    n++;
}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    size_t lenght = 5;

    std::cout << "=== Before increment values ===" << std::endl;
    std::cout << "Array Content : ";
    ::iter(array, lenght, printInt);
    std::cout << std::endl;

    std::cout << "=== After increment values ===" << std::endl;
    ::iter(array, lenght, increment);
    std::cout << "Array Content : ";
    ::iter(array, lenght, printInt);
    std::cout << std::endl;

    return 0;
}
