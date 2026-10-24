#include <iostream>
#include <algorithm>
#include "Memoization.h"
#include "Bottom_UP.h"
#include "Count_Paths.h"

int memo[1001];

int main(){
    int memoArr[] = {1, 4, 7, 10};

    // MEMOIZATION
    std::cout << "Memoization\n";
    for (int t : memoArr){
        for(int i = 0; i <= t; i++)
            memo[i] = -1;
        std::cout << "n = " << t << "  ->  minimum steps = " << getMinStepsMemo(t, memo) << '\n';
    }

    // BOTTOM UP
    std::cout << "\nBottom Up Dp\n";
    for (int t : memoArr){
        std::cout << "n = " << t << "  ->  minimum steps = " << getMinStepsBottomUp(t, memo) << '\n';
    }
    
    // SUPPLEMENTARY: Count Paths with Cost
    int matrix[4][4] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 25;
    std::cout << "\nNumber of valid paths: " << countPathsWithCost(matrix, 0, 0, targetCost) << '\n';

    return 0;
}