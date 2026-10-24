#include <iostream>

const int Max = 20;

class GraphMatrix{
    char vertices[Max];
    int matrix[Max][Max];
    int verticesCount;
    bool directed;

    int indexOf(char v){
        for(int i = 0; i < verticesCount; i++)
            if(vertices[i] == v) return i;
        return -1;
    }

public: 
    GraphMatrix(bool isDirected){
        verticesCount = 0;
        directed = isDirected;
        for(int i = 0; i < Max; i++)
            for(int j = 0; j < Max; j++)
                matrix[i][j] = 0;
    }

    void addVertex(char v){
        if(indexOf(v) != -1 || verticesCount == Max) return;
        vertices[verticesCount] = v;
        verticesCount++;
    }

    void addEdge(char a, char b, int weight = 1){
        int i = indexOf(a);
        int j = indexOf(b);
        if(i == -1 || j == -1) return;
        matrix[i][j] = weight;
        if(!directed) matrix[j][i] = weight;
    }

    void displayVertices(){
        std::cout << "Vertices: ";
        for(int i = 0; i < verticesCount; i++)
            std::cout << vertices[i] << " ";
        std::cout << std::endl;
    }

    void displayMatrix(){
        std::cout << " ";
        for(int i = 0; i < verticesCount; i++)
            std::cout << " " << vertices[i];
        std::cout << std::endl;
        for(int i = 0; i < verticesCount; i++){
            std::cout << vertices[i];
            for(int j = 0; j < verticesCount; j++)
                std::cout << " " << matrix[i][j];
            std::cout << std::endl;
        }
    }
};



int main() {
    std::cout << "Undirected Graph" << std::endl;
    GraphMatrix g1(false);
    g1.addVertex('A');
    g1.addVertex('B');
    g1.addVertex('C');
    g1.addVertex('D');
    g1.addVertex('E');
    g1.addEdge('A', 'B');
    g1.addEdge('A', 'C');
    g1.addEdge('A', 'D');
    g1.addEdge('B', 'E');
    g1.addEdge('C', 'D');
    g1.addEdge('D', 'E');
    g1.displayVertices();
    g1.displayMatrix();

    std::cout << std::endl << "Weighted Graph" << std::endl;
    GraphMatrix g2(true);
    g2.addVertex('A');
    g2.addVertex('B');
    g2.addVertex('C');
    g2.addVertex('D');
    g2.addVertex('E');
    g2.addEdge('A', 'B', 4);
    g2.addEdge('A', 'C', 3);
    g2.addEdge('C', 'D', 2);
    g2.addEdge('D', 'B', 1);
    g2.addEdge('D', 'E', 1);
    g2.addEdge('E', 'A', 1);
    g2.displayVertices();
    g2.displayMatrix();
    return 0;
}