#include <iostream>

const int MAX = 20;

class Graph{
    char vertices[MAX];
    char edgesFrom[MAX][MAX];
    char edgesTo[MAX][MAX];
    int verticesCount;
    int edgesCount;

    bool exists(char v) {
        for (int i = 0; i < verticesCount; i++)
            if (vertices[i] == v) return true;
        return false;
    }
public:
    Graph() {
        verticesCount = 0;
        edgesCount = 0;
    }

    void addVertex(char v) {
        if (exists(v)) {
            std::cout << "Vertex " << v << " already exists" << std::endl;
            return;
        }
        if (verticesCount == MAX) {
            std::cout << "Graph is full" << std::endl;
            return;
        }
        vertices[verticesCount] = v;
        verticesCount++;
    }

    void addEdge(char a, char b) {
        if (!exists(a) || !exists(b)) {
            std::cout << "Vertex not found" << std::endl;
            return;
        }
        edgesFrom[edgesCount][0] = a;
        edgesTo[edgesCount][0] = b;
        edgesCount++;
    }

    void displayVertices() {
        std::cout << "Vertices: ";
        for (int i = 0; i < verticesCount; i++)
            std::cout << vertices[i] << " ";
        std::cout << std::endl;
    }

    void displayEdges() {
        std::cout << "Edges: ";
        for (int i = 0; i < edgesCount; i++)
            std::cout << "(" << edgesFrom[i][0] << ", " << edgesTo[i][0] << ") ";
        std::cout << std::endl;
    }
};

int main(){
    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.displayVertices();
    g.displayEdges();
    return 0;
}