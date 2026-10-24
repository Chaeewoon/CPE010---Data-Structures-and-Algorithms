#ifndef SUPPQUEUE_H
#define SUPPQUEUE_H

#include <iostream>
#include <string>

class Job{
public:
    int jobID;
    std::string idName;
    int pages;

    Job(){
        jobID = 0;
        idName = "";
        pages = 0;
    }
    Job(int i, std::string n, int p){
        jobID = i;
        idName = n;
        pages = p;
    }
};

//create a class the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T> *next;
};

//creates the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

//enqueue operation
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    //create the new node
    qNode<T>* newNode = new_node(newData);

    //inserting into an empty queue
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    //inserting an item into a non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

//dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a temporary node 
    qNode<T>* deleteNode = nullptr; // temp variable
    deleteNode = (*frontPtr);
    
    //check if the queue has only 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    //delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

template <typename T>
bool isEmpty(qNode<T>** frontPtr){
    return (*frontPtr) == nullptr;
}


class Printer{
private:
    qNode<Job>* front;
    qNode<Job>* back;

public: 
    Printer(){
        front = nullptr;
        back = nullptr;
    }

    void addJob(Job newJob){
        enqueue(newJob, &front, &back);
        std::cout << "Job added to the queue: " << newJob.idName << std::endl;
        std::cout << "Job ID: " << newJob.jobID << std::endl;
        std::cout << "Pages: " << newJob.pages << std::endl;
    }

    void processJob(){
        if(isEmpty(&front)){
            std::cout << "No jobs in the queue to process." << std::endl;
            return;
        }
        Job jobToProcess = front->data;
        std::cout << "Processing job: " << jobToProcess.idName << std::endl;
        std::cout << "Job ID: " << jobToProcess.jobID << std::endl;
        std::cout << "Pages: " << jobToProcess.pages << std::endl;
        dequeue(&front, &back);
    }

    void processAllJobs(){
        if(isEmpty(&front)){
            std::cout << "No jobs in the queue to process." << std::endl;
            return;
        }
        while(!isEmpty(&front)){
            processJob();
        }
    }

};

#endif