#include <iostream>
#include "simply_LL.h"

int main(){
    //  creating an empty list also allocate memory
    SimplyList<char>* head= new SimplyList<char>; //x1001
    SimplyList<char>* second= new SimplyList<char>; //x1002
    SimplyList<char>* third= new SimplyList<char>; //x1003
    SimplyList<char>* fourth= new SimplyList<char>; //x1004
    SimplyList<char>* fifth= new SimplyList<char>; //x1005

    //assign the data
    head->data = 'G'; // the head has the J letter now
    head->next = second; // the next address
    
    second->data = 'A'; 
    second->next = third;

    third->data = 'B';
    third->next = fourth;

    fourth->data = 'Q';
    fourth->next = nullptr;

    std::cout << "Original List:" << std::endl;
    listTraversal(head);

    std::cout << "Inserting a new node at the head: " << std::endl;
    sllinserHead('Q',&head);
    listTraversal(head);

    std::cout << "Inserting a new node at the third: " << std::endl;
    sllGeneralIInsert('X', head->next->next);
    listTraversal(head);

    std::cout << "Inserting a new node at the END: " << std::endl;
    sllInsertEnd('U', &head);
    listTraversal(head);

    std::cout << "Deleting a node: " << std::endl;
    sllDeleteNode('Q', &head);
    listTraversal(head);

    std::cout << "Deleting all the node: " << std::endl;
    sllDeleteList(&head);
    listTraversal(head);


   return 0;
}