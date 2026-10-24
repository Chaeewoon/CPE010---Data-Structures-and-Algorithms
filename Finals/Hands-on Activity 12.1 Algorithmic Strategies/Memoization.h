#ifndef MEMOIZATION_H
#define MEMOIZATION_H

#include <iostream>
#include <algorithm>

int getMinStepsMemo(int n, int memo[]){
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    int r = 1 + getMinStepsMemo(n-1, memo);
    if (n%2 == 0) r = std::min(r, 1 + getMinStepsMemo(n/2, memo));
    if (n%3 == 0) r = std::min(r, 1 + getMinStepsMemo(n/3, memo));
    memo[n] = r;
    return r;
}

#endif