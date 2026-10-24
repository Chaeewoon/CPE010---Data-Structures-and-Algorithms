#ifndef BOTTOM_UP_H
#define BOTTOM_UP_H

#include <iostream>
#include <algorithm>

int getMinStepsBottomUp(int n, int memo[]){
    int dp[n+1], i;
    dp[1] = 0;
    for( i = 2 ; i <= n ; i ++ ){
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = std::min(dp[i], 1+ dp[i/2]);
        if(i%3==0) dp[i] = std::min(dp[i], 1+ dp[i/3]);
    }
    return dp[n];
}

#endif