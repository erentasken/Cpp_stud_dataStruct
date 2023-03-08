#include <iostream>
#include "MyGraph.h"
#include <string>

using namespace std;

int main(void){

    string filename;
    int element;
    cout << "Enter filename " << endl;
    getline(cin,filename);
    MyGraph Gr(filename);
    Gr.print();
    Gr.convert_adj_matrix();
    Gr.DFS(1);



}
