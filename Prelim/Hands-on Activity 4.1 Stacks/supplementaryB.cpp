#include <iostream>
#include <string>
#include "supplementaryb.h"
 
int main(){
   std::string opening = "([{";
    std::string closing = ")]}";
    std::string choice;
    bool balanced = true;
 
    std::cout << "Balanced Symbol Checker (Array Stack)" << std::endl;
    std::cout << "Enter Expression: ";
    std::cin >> choice;
 
    for (int i = 0; i < choice.length(); i++) {
 
    if (opening.find(choice[i]) != std::string::npos) {
        push(choice[i]);
    }
    else if (closing.find(choice[i]) != std::string::npos) {
 
        if (isEmpty<char>()) {
            balanced = false;
            break;
        }
 
        if (!isOpenClose(pop<char>(), choice[i])) {
            balanced = false;
            break;
            }
        }
    } 
 
    if (!isEmpty<char>()) {
        balanced = false;
    }
 
    if (balanced)
        std::cout << "Balanced Expression";
    else
        std::cout << "Unbalanced Expression";
        
    return 0;
}