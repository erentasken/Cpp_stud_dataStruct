#include <iostream>
using namespace std;
class Graph{
    private:
    int numVertices;
    public:
    
    bool **adjMatrixEntry;
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjMatrixEntry = new bool*[numVertices];
        for(int r = 0; r < numVertices; r++){
            adjMatrixEntry[r] = new bool[numVertices];
            for(int c = 0; c < numVertices; c++){
                adjMatrixEntry[r][c] = false;
            }
        }
    }

    void printGraph(){
        for(int r = 0; r < numVertices; r++){
            for(int c = 0; c < numVertices; c++){
                cout << adjMatrixEntry[r][c] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    void addEdge(int column, int row){
        adjMatrixEntry[column][row] = true;
        adjMatrixEntry[row][column] = true;            
    }

    void removeEdge(int column, int row){
        adjMatrixEntry[column][row] = false;
        adjMatrixEntry[row][column] = false;
    }

    ~Graph(){
        for(int i = 0; i < numVertices; i++) delete adjMatrixEntry[i];
        delete adjMatrixEntry;
    }

};
int main(){
    Graph myGraph(5);
    myGraph.printGraph();
    myGraph.addEdge(1,2);
    myGraph.printGraph();
    return 0;
}