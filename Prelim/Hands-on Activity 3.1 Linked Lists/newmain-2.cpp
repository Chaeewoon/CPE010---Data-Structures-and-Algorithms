#include <iostream>
#include "simply_LL.h"
#include "doubly_LL.h"

int main(){

    //creating the first node
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Traversal Testing:" << std::endl;
    dllTrraverse(head);

    std::cout << "Traversal Head Testing:" << std::endl;
    dllInsertHead('X', &head);
    dllTrraverse(head);

    std::cout << "Traversal End Testing:" << std::endl;
    dllInsertEnd('1', head);
    dllTrraverse(head);

    std::cout << "Traversal General Testing:" << std::endl;
    dllGeneralInsert('R', head->next);
    dllTrraverse(head);
    
    std::cout << "Delete:" << std::endl;
    dllDeleteNode('R', &head);
    dllTrraverse(head);
    return 0;
}