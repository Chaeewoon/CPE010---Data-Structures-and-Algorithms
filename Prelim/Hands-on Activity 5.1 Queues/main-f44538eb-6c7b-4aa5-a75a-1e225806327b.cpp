#include <iostream>
#include "suppQueue.h"

int main(){
    Printer myPrinter;

    std::cout << "Adding jobs to the queue..." << std::endl;
    myPrinter.addJob(Job(1, "Dirk Sotto", 5));
    myPrinter.addJob(Job(2, "John Victoria", 10));

    std::cout <<"\nProcessing jobs in the queue..." << std::endl;
    myPrinter.processJob();

    std::cout <<"\n Adding more jobs to the queue..." << std::endl;
    myPrinter.addJob(Job(3, "Alice Volkswagon", 15));
    myPrinter.addJob(Job(4, "King Bob", 20));

    std::cout <<"\nProcessing remaining jobs in the queue..." << std::endl;
    myPrinter.processAllJobs();

    std::cout <<"\nProcessing remaining jobs in the queue..." << std::endl;
    myPrinter.processAllJobs();


    return 0;
}