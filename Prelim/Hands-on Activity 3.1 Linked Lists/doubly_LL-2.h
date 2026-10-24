#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};


//create a new node:
template <typename T>
DoubleList<T>* createNode(T newData){
    //dynamically allocate memory for the new node
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // return the address of the newly created node
    return newNode;
}

template<typename T>
void dllTrraverse(DoubleList<T> *currentNode){

    DoubleList<T> *tail;

    if(currentNode == nullptr){
        std::cout<<"List is empty"<< std::endl;
    }


    //forward traversing:
    std::cout << "Forward: " <<std::endl;

    while(currentNode != nullptr){
        //printed the data
        std::cout<<currentNode->data << " ";
        //save the currentNode as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }

    std::cout<<std::endl;
    //backward traversing
    std::cout<<"Backward: "<<std::endl;
    while(tail != nullptr){
        //print the data
        std::cout << tail->data<< " ";
        //move towards the prev node
        tail = tail->prev;
    }
    std::cout<<std::endl;
} 

template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //create a node
    DoubleList<T> *newNode = createNode(newData);

    // new node should point to the current head
    newNode->next = *currentHead;

    //current head should point back to the new
    (*currentHead)->prev = newNode;

    // update the header pointer
    *currentHead = newNode;
}


template<typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){
     //create a node
    DoubleList<T> *newNode = createNode(newData);

    //traverse to the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    //connect the alst nodde to the new node
    currentHead->next = newNode;
    //connect the new node back to the last node
    newNode->prev = currentHead;
}

template<typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    //Check if it is the head node (previous node is null)
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }
    // Allocate a new node
    DoubleList<T>* newNode = createNode(newData);
    //Store data in the new node
    newNode->data = newData;

    //Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode; 
    }

    //Point previous node to the new node
    prevNode->next = newNode;

}


template<typename T>
void dllDeleteNode(T findData, DoubleList<T>** currentHead){

    if (*currentHead == nullptr) return;


    DoubleList<T>* currNode = *currentHead;
    DoubleList<T>* prevNode = nullptr;

    //Find previous node of the node to be deleted.
    while(currNode != nullptr && currNode->data != findData){
        prevNode  = currNode;
        currNode = currNode->next;
    }

    //Change the next of previous node.

    if(prevNode == nullptr){
        *currentHead = currNode->next;
    }
    
    else{
        prevNode->next = currNode->next;
    }

    if(currNode->next != nullptr){
        currNode->next->prev = currNode->prev;
    }

    //Free memory for the node to be deleted.
    delete currNode;

}







#endif