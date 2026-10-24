#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

template <typename T>
class SimplyList{
    public: 
        T data;
        SimplyList<T> *next = nullptr;
};

template <typename T>
void listTraversal(SimplyList<T>* head){
    
    if(head == nullptr){
        std::cout << "List is Empty" << std::endl;
        return;
    }

    while(head != nullptr){
        std::cout << head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
    std::cout<<std::endl;
}


template <typename T>
void sllinserHead(T newData, SimplyList<T>** currentHead){ // getting the address of head
    SimplyList<T>* newNode = new SimplyList<T>; // allocate memory for the new node
    newNode->data = newData; // put our data into the new node
    newNode->next = *currentHead; // set next of the new node to point to the previous head
    *currentHead = newNode; //reset head to point to the new node
}

template <typename T>
void sllGeneralIInsert(T newData, SimplyList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }

    SimplyList<T>* newNode = new SimplyList<T>; //Allocate a new node
    newNode->data = newData; //Store data in the new node
    newNode->next = prevNode->next; // Point new node to the node previous node was pointing to
    prevNode->next = newNode; // Point previous node to the new node
}

template <typename T>
void sllInsertEnd(T newData, SimplyList<T>** head){
    SimplyList<T>* newNode = new SimplyList<T>; // allocate new node
    SimplyList<T>* currentNode = *head; //dereference to the head node
    newNode->data = newData; // store data in new node
    newNode->next = nullptr; // point next of new node to NULL

    // Traverse the list until next of the node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    //Point the next of the current node to the new node
    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    //check if there is no list to be deleted
    if (*head == nullptr){
        return;
    }
    
    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    //searching loop need both to be true
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    //data was mot found
    if(currNode == nullptr){
        return;
    }

    // what if the head node need to be deleted
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    // we have to delete the node?
    delete currNode;

}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T> *temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif