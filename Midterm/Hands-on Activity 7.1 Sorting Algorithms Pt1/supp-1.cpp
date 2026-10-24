#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingSupp.h"

const int maxSize = 100;
const int numCandidates = 5;

int main(){
    int votes[maxSize];
    std::string candidates[numCandidates] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        votes[i] = rand() % numCandidates + 1;
    }

    std::cout << "Unsorted votes: ";
    displayArray(votes, maxSize);
    std::cout << std::endl;

    std::cout <<"Sorted votes: ";
    selectionSort(votes, maxSize);
    displayArray(votes, maxSize);
    std::cout << std::endl;

    countVotes(votes, maxSize);

    return 0;
}