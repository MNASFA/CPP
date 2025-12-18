#include "Serializer.hpp"
#include <iostream>

int main(){
    Data original;
    original.name = "Houssam";
    original.age = 23;
    original.salary = 1000.00;

    std::cout << "==== Test 1 : Original Data ====" << std::endl;
    std::cout << std::endl;
    std::cout << "Address : " << &original << std::endl;
    std::cout << "Name : " << original.name << std::endl;
    std::cout << "Age : " << original.age << std::endl;
    std::cout << "Salary : " << original.salary << std::endl;

    std::cout << std::endl;
    std::cout << "==== Test 2 : Serialized ====" << std::endl;
    std::cout << std::endl;
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Address as a integer value : " << serialized << std::endl;

    std::cout << std::endl;
    std::cout << "==== Test 3 : Deserialized ====" << std::endl;
    std::cout << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Address : " << deserialized << std::endl;
    std::cout << "Name : " << deserialized->name << std::endl;
    std::cout << "Age : " << deserialized->age << std::endl;
    std::cout << "Salary : " << deserialized->salary << std::endl;

    std::cout << std::endl;
    std::cout << "==== Test 4 : Verification ====" << std::endl;
    std::cout << std::endl;
    if (deserialized == &original){
        std::cout << "Success Adresses are equal." << std::endl;
        std::cout << "Deserialized ponter points to the original data" << std::endl;
    }
    else
        std::cout << "Error : Pointers are not equal" << std::endl;

 }