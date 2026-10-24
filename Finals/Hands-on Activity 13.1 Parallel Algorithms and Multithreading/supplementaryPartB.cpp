#include <iostream>
#include <thread>

int globalVar = 0;

// Multithreading
void add(int n) {
    globalVar += n;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Initial value: " << globalVar << std::endl;

    T1.join();
    std::cout << "After T1.join(): " << globalVar << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << globalVar << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << globalVar << std::endl;

    return 0;
}