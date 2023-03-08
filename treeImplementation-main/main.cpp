#include "tree.h"
#include <iostream>
using namespace std;

int main(){

    Tree<int> tree;
    tree.insert(9);
    tree.insert(7);
    tree.insert(12);
    tree.insert(8);
    tree.insert(10); 
    tree.insert(15);
    tree.insert(17);
    tree.insert(27);

    
    cout << "The height of given tree in the figure is " <<tree.height(tree.root) << endl;

    vector <int> v;
    v = tree.findOnlyChilds(tree.root);
    
    cout << "The only children in the given figure are ";
    for(int i =0; i< v.size();i++){
        cout << v[i] << ", ";
    }
}
