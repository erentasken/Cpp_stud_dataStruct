#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include "intSLList.h"
#include <fstream>
#include <string>
#include <stack>

using namespace std;
class MyGraph{
private:
    bool error;
	IntSLList **listoflist;
	int arraysize;
	int *CheckList;
	void TurnDefault(void){
		for(int i=0;i<arraysize+1;i++){
			CheckList[i] = -1;
		}
	}
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
		CheckList = new int [arraysize+1];
		TurnDefault();
		listoflist = new IntSLList *[arraysize];
		for(int i = 0;i<arraysize;i++){
			listoflist[i] = new IntSLList;
		}


		int from,to;
		int i = 0;
		while(file.eof() == false){
			file>>from;
			file>>to;


			listoflist[from-1]->addToTail(to);
		}
	}

	~MyGraph(){
        if(error == true) return;
		for(int i=0;i<arraysize;i++){
			delete listoflist[i];

		}
		delete [] listoflist;
		delete [] CheckList;
	}
	void print(void){
		for(int i = 0;i<arraysize;i++){
			cout << "Adjacencies of " << i+1 << "= ";
			listoflist[i]->printAll();
		}
	}
	void convert_adj_matrix(){
		bool** matrix;
		matrix = new bool*[arraysize];
		
		for(int r = 0; r < arraysize; r++){
			matrix[r] = new bool[arraysize];
			for(int c = 0; c < arraysize; c++){
				matrix[r][c] = false;
			}
		}

		for(int i = 0; i<arraysize;i++){
			for(int j = 0; j < listoflist[i]->GetSize(); j++) matrix[i][(listoflist[i]->GetAt(j+1))-1] = true;
		}

		for(int r = 0; r < arraysize; r++){
			for(int c = 0; c < arraysize; c++){
				cout << matrix[r][c] << "\t";
			}
			cout << "\n";
		}
}
	void DFS(int v){
		bool* visited = new bool[arraysize];
		stack<int> stack;
		stack.push(v);

		while(!stack.empty()){
			
			v = stack.top();
			cout << v << " ";
			stack.pop();

			if(!visited[v]){
				visited[v] = true;
			}
			
			for(int j = 1; j < listoflist[v-1]->get_size()+1; j++){
				if(!visited[(listoflist[v-1]->GetAt(j))]){
					stack.push(listoflist[v-1]->GetAt(j));
				}
			}

		}




	}
};

#endif
