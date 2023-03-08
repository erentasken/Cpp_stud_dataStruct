#include <iostream>
using namespace std;



class Graph{
    private:
        int n;
    public:
        bool **matrix;
        Graph(int n){//nxn matrix initialization
            this->n = n;
            matrix = new bool*[n]; // initialization of rows
            for(int row = 0; row < n; row++){
                matrix[row] = new bool[n]; // initialization of columns for each row.
                for(int column = 0; column < n; column++){
                    matrix[row][column] = false;
                }
            }
        }
        
        void addEdge(int src, int dest){
            matrix[src][dest] = true;
            matrix[dest][src] = true; 
        }

        void printGraph(){
            for(int row = 0; row < n; row++){
                for(int column = 0; column < n; column++){
                    cout << matrix[row][column] << " ";
                }
                cout << "\n";
            }

            cout << "\n \n" << endl;
        }

};

int main(){

    Graph graph(4);

    graph.printGraph();

    graph.addEdge(2,3);

    graph.printGraph();

    return 0;
}