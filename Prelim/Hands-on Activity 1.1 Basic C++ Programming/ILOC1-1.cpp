#include <iostream>

int main(){

    int a = 67;
    int b = 69;
    int temp = 0;

    std::cout << "Before swapping values" << std::endl;
    std::cout << "The value of a is: " << a << std::endl;
    std::cout << "The value of b is: " << b << std::endl;

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nAfter swapping values" << std::endl;
    std::cout << "The value of a is: " << a << std::endl;
    std::cout << "The value of b is: " << b << std::endl;

    return 0;
}