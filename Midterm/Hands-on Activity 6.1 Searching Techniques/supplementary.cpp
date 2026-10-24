#include <iostream>
#include <cstdlib> 
#include <time.h>
#include "node.h"
#include "suppAlgo.h"


int main(){
    //Problem 1
    //array
    int sequentialArr[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    std::cout << "Array Sequential Search: ";
    int arrayComparisons = sequentialSearchArr(10, 18, sequentialArr);
    std::cout << "\nTotal comparisons: " << arrayComparisons;

    //linked list
    Node<int> *value1 = new_node(15);
    Node<int> *value2 = new_node(18);
    Node<int> *value3 = new_node(2);
    Node<int> *value4 = new_node(19);
    Node<int> *value5 = new_node(18);
    Node<int> *value6 = new_node(0);
    Node<int> *value7 = new_node(8);
    Node<int> *value8 = new_node(14);
    Node<int> *value9 = new_node(19);
    Node<int> *value10 = new_node(14);

    value1->next = value2;
    value2->next = value3;
    value3->next = value4;
    value4->next = value5;
    value5->next = value6;
    value6->next = value7;
    value7->next = value8;
    value8->next = value9;
    value9->next = value10;
    value10->next = nullptr;

    std::cout << "\nLinked List Sequential Search: ";
    int llComparisons = sequentialSearchLL(value1, 18);
    std::cout << "\nTotal comparisons: " << llComparisons;


    //problem 2
    int arrCount = repetitionSearchArr(10, 18, sequentialArr);
    std::cout << "\nThe repetition of 18 in the Array is: " << arrCount;
    int llCount = repetitionSearchLL(value1, 18);
    std::cout << "\nThe repetition of 18 in the linked list is: " << llCount;


    //problem 3
    int binaryList[10] = {3,5,6,8,11,12,14,15,17,18};
    std::cout << "\nArray: ";
    binarySearchAlgo(10, 8, binaryList);

    //problem 4
    std::cout << "\nArray recursive: ";
    binarySearchAlgoRecursive(binaryList, 0, 9 ,12);
    return 0;
}
