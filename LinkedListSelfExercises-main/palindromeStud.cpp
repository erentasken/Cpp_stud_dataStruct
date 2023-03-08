#include <iostream>
using namespace std;
class Node {
  public:
  int data;
  Node * next;
};

int main()
{

    Node *head = NULL;
    Node *prev;

    for( int i = 0; i < 5; i++ ){
        Node *temp = new Node();
        temp->data = i;

        if( head == NULL){
            head = temp;
            prev = head;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
    }

    



    while( cur != NULL ){
        cout << cur->data << " ";
        cur = cur -> next;
    }

}