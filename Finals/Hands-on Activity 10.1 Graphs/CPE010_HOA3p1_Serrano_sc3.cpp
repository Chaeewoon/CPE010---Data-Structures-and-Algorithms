#include "sc3.h"
#include <iostream>

int main(){

    graphEdge edges[] = {{0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}};
    int N = 6;
    int n = sizeof(edges)/sizeof(edges[0]);
    DiaGraph diagraph(edges, n, N);
    std::cout<<"Graph adjacency list "<<std::endl<<"(start_vertex, end_vertex, weight):"<<std::endl;
    for (int i = 0; i < N; i++){
        display_AdjList(diagraph.head[i], i);
    }
    return 0;
}



