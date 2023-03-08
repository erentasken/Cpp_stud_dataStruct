#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};
 

class Graph{
    private:
        bool* visited = new bool[V];
        bool* visited1 = new bool[V];
        int V;
        struct AdjList* array; // list of linked lists
    public:
    
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL; // IMPORTANT
        }

        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }

        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);            
            
            newNode->next = array[src].head;
            array[src].head = newNode;
            
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        
        }

        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }

        void DFSiter(int a){    
            stack<int> stack;
            stack.push(a);
            while(!stack.empty()){
                a = stack.top();
                stack.pop();
                if(!visited[a]){
                    cout << a << " ";
                    visited[a] = true;
                }
                for(AdjListNode* iter = array[a].head; iter; iter = iter->next){
                    if(!visited[iter->dest]){
                        stack.push(iter->dest);
                    }
                }

            }

        }

        void DFSrecursive(int v){
                
                visited1[v] = true;
                cout << v << " ";
                for( AdjListNode* iter = array[v].head; iter; iter = iter->next ){
                    if(!visited1[iter->dest]) DFSrecursive(iter->dest);
                }
                
            }

        
};

 
int main() 
{
    Graph gh(5);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(2, 1);
    gh.addEdge(2, 3);
    gh.addEdge(2, 4);
    gh.addEdge(3, 1);
    gh.addEdge(3, 2);
    gh.addEdge(3, 4);
    gh.addEdge(4, 2);
    gh.addEdge(4, 3);
 
    gh.printGraph();

    cout << "\n \n";

    cout << "Recursive DFS traverse: "; gh.DFSrecursive(2);

    cout << "\n \n";
    cout << "Iterative DFS travere: "; gh.DFSiter(2);
    

    cout << "\n \n";

    

 
    return 0;
}