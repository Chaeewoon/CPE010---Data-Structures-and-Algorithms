#include <iostream>
#include <string>

const int maxCap = 100;
char stack[maxCap];
int top = -1;

bool isEmpty();
void push(char newData);
char pop();
bool isOpenClose(char opening, char closing);

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

        if (isEmpty()) {
            balanced = false;
            break;
        }

        if (!isOpenClose(pop(), choice[i])) {
            balanced = false;
            break;
            }
        }
    } 

    if (!isEmpty()) {
        balanced = false;
    }

    if (balanced)
        std::cout << "Balanced Expression";
    else
        std::cout << "Unbalanced Expression";
        
    return 0;
}

bool isEmpty(){
    return top == -1;
}

void push(char newData){
    top++;
    stack[top] = newData;
}

char pop(){
    char newData = stack[top];
    top--;
    return newData;
}

bool isOpenClose(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}