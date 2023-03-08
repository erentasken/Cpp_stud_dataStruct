#include <iostream>
using namespace std;
class Node {
  public:
  int data;
  Node * next;
};

Node * doReverse( Node *head){ //****
    Node *prev = NULL;
    Node *current = head;//****
    Node *next = NULL;
    while( current != NULL){
        next = current->next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev; //****
    return head; //****
}


int main()
{
  Node *head = NULL;
  Node *prev;

  for (int i=0; i< 4;i++){
    Node *temp = new Node();
    temp->data = i;
    if (head == NULL){
      head = temp;
      prev = head;
    }
    else{
      prev->next = temp;
      prev = temp;
    }
  } // Linked list oluşturan sana attığım for loop burası. 

  head = doReverse(head); //****
  
  while( head!=NULL){
    cout << head->data << " ";
    head = head->next;
  }
}