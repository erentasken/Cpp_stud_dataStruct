#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void printLinkList( Node *r) { 
    while(r != NULL){
        cout << r -> data << " ";
        r = r -> next;
    }
}

void addItem(Node *r) { 
    while( r -> next != NULL) r = r -> next;

    for(int i = 0; i < 3; i++ ){
        r -> next = new Node();
        r = r -> next;
        r -> data = i*31;
        r -> next = NULL;
    }
 }

Node * addItemSeq(Node *r, int newItem){

    if( r == NULL){  // first element added to the list 
        r = new Node();
        r -> next = NULL;
        r -> data = newItem;
        return r;
    }

    if( r->data > newItem){ // always updates the root if there is new root, which is smaller than the previous root.
        Node *temp = new Node();
        temp -> data = newItem;
        temp -> next = r;
        return temp; // added item is the new root.
    }
// if there is not a new root then, 
    Node *iter = r;

    while( iter->next != NULL && iter->next->data < newItem){
        iter = iter->next;
    }
    Node *temp = new Node();
    temp->next = iter->next;
    iter->next = temp;
    temp->data = newItem;
    return r; 
}

Node *deleteItem(Node *r, int item ){
    Node *temp;
    Node *iter;
    iter = r;
    if( item == r -> data){
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while( iter->next->data != item && iter != NULL ){
        iter = iter->next;
    }
    if(iter == NULL){
        return r;
    }

    temp = iter -> next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

int main(){

    Node * root;
    root = NULL;
//nodes are created.


//insertion operation v
//    for( int i = 0; i < 2; i++) iter = iter -> next; 
//
//    Node * temp = new Node();

//    temp -> next = iter -> next;
//    iter -> next = temp;
//    iter -> data = 5;  
//insertion operation 

    root = addItemSeq(root, 5);
    root = addItemSeq(root, 2);
    root = addItemSeq(root, 9);
    root = addItemSeq(root, 3);
    root = addItemSeq(root, 6);
    root = addItemSeq(root, 4);


    root = deleteItem(root, 4);

    printLinkList(root);


    return 0;
}