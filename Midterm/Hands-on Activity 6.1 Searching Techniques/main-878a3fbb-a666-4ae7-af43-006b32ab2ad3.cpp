#include <iostream>
#include <cstdlib> 
#include <time.h>
#include "node.h"
#include "searchAlgo.h"

const int max_size = 50;

int main(){

    //generate
    int dataset[max_size];
    srand(time(0));
    for(int i= 0; i < max_size; i++){
        dataset[i] = rand();
    }

    for(int i = 0; i < max_size; i++){
        std::cout<< dataset[i] <<" ";
    }
    std::cout<<std::endl;


    int userInput;
    std::cout<<"What number to search? ";
    std::cin >> userInput;
    linearSeachArr(max_size, userInput, dataset);  

    //create linklist:
    Node<char> * name1 = new_node('G');
    Node<char> * name2 = new_node('A');
    Node<char> * name3 = new_node('B');

    name1->next = name2;
    name2->next = name3;
    name3->next = nullptr;


    std::cout <<"Linked list Linear Search :";
    linearSearchLL(name1, 'B');
    std::cout <<"Linked list Linear Search :";
    linearSearchLL(name1, 'C');

    //creating an array binary
    int sortedArr[7] = {1,2,3,4,5,6,7};

    std::cout << "Array Binary Search: ";
    binarySearchArr(8,6, sortedArr);
    std::cout << "Array Binary Search: ";
    binarySearchArr(8,10, sortedArr);


    //add your main driver code here

    Node<int> * value1 = new_node(10);
    Node<int> * value2 = new_node(20);
    Node<int> * value3 = new_node(30);

    value1->next = value2;
    value2->next = value3;
    value3->next = nullptr;


    std::cout << "Linked list Binary Search :";
    binarySearchLL(value1, 30);

    std::cout << "Linked list Binary Search :";
    binarySearchLL(value1, 29);

}