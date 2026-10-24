#ifndef SUPPLEMENTARY_B_H
#define SUPPLEMENTARY_B_H
#include <string>


//class node with data and next members
template <typename T>
class Node{
    public:
    T data;
    Node<T> *next = nullptr;
};


//create a pointer/reference tip that always points to curren top node


//global
template <typename T>
Node<T>* head = nullptr;


//pushing operation
template <typename T>
void push(T newData){
    //create a new node
    Node<T>* newNode = new Node<T>;


    //assign the data to the newnode
    newNode->data = newData;


    //pointer the newNode next to the current top
    newNode->next = head<T>;


    //assign the new Top to the newNode
    head<T> = newNode;


}
//isEmpty Operation
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}


template <typename T>
T pop(){
    //if the stack is empty error catch
    if(isEmpty<T>()){
        std::cout<<"Stack Underflow"<< std::endl;
    }
    //saving a current top node to a temporary variable
    Node<T> *temp = head<T>;
    //store the data to a temporary variable
    T tempVal = temp->data;
    //move the head to next node
    head<T> = head<T>->next;
    //free up the memory
    delete temp;
    //return the temporary variable
    return tempVal;
}


template<typename T>
void Top(){
    //what if the stack is empty
    if(isEmpty<T>()) return;


    std::cout<<"The Top is: " << head<T>->data;


}

template <typename T>
void displayAll(){
    if(isEmpty<T>()) return;


    while(head<T> != nullptr){
        std::cout << head<T>->data <<" ";
        head<T> = head<T>->next;
    }
}

bool isOpenClose(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '{' && closing == '}') return true;
    if (opening == '[' && closing == ']') return true;
    return false;
}
#endif

