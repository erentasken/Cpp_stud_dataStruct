#include <iostream>
#include "MyGraph.h"
#include <string>


using namespace std;

int main(){
    string filename;
    int element;
	MyGraph Gr("input.txt");
    Gr.print();
    Gr.convert_adj_matrix();
    cout << endl;
    cout <<"isConnected: "<<Gr.isConnected (5, 4) << endl;
}
