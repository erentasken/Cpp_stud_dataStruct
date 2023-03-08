#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include "intSLList.h"
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;
class MyGraph{
private:
    bool error;
	IntSLList **listoflist;
	int arraysize;
	
	bool **adjMatrix;
	bool *listChecker;
	bool *visited;
public:
	MyGraph(string filename){
		ifstream file;
		file.open(filename.c_str());
		file >> arraysize;
		if(file.is_open() == false){
            cout << "Couldn't open the file" << endl;
            error = true;
            return;
		}
		error = false;

		file.close();

		ifstream myFile(filename);
		int src; int dest;int garbage;
		myFile>>garbage;
		listoflist = new IntSLList*[arraysize];
		listChecker = new bool[arraysize];

		while(!myFile.eof()){
			myFile>>src;
			myFile>>dest;
			src--;

			if(!listChecker[src]){
				listoflist[src] = new IntSLList[arraysize];
				listChecker[src]=1;
			}
			listoflist[src]->addToTail(dest);
		}
	}

	void print(void){

		for(int i=0;i<arraysize;i++){
			cout << "Adjacencies of " << i+1 << "= ";
			if(listChecker[i]) listoflist[i]->printAll();
			else cout << "\n";
		}
	}
	void convert_adj_matrix(){
		cout << "\n \n \n";
		//initializing the adj matrix as a zero matrix
		adjMatrix = new bool*[arraysize];
		for(int r = 0; r < arraysize; r++){
			adjMatrix[r] = new bool[arraysize];
			for(int c = 0; c < arraysize; c++){
				adjMatrix[r][c] = false;
			}
		}
		for(int i = 0; i<arraysize;i++){
			if(listChecker[i]){
				for(int j = 0; j < listoflist[i]->GetSize(); j++) adjMatrix[i][(listoflist[i]->GetAt(j+1))-1] = true;
			}
		}
}

	bool isConnected (int src, int dest){
		stack<int> stack;
		visited = new bool[arraysize];
		stack.push(src);
		int var;
		while(!stack.empty()){
			var = stack.top();
			stack.pop();
			for(int c = 0; c < arraysize; c++){
				if(adjMatrix[var-1][c] && !visited[c]){
					visited[c] = true;
					stack.push(c);
					if(dest-1 == c) return 1;
				}
			}
		}
		return 0;
	}
};

#endif