// C++ program to swap two given nodes of a linked list
#include <iostream>
using namespace std;

// A linked list node class
class Node {
public:
	int data;
	class Node* next;
};

void printList(Node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
}

void reverseList(Node **head){
	Node *cur = (*head);
	Node *prev = NULL;
	Node *next = NULL;

	while( cur!= NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	(*head) = prev;
}

// Function to add a node at the beginning of List
void push(Node** head_ref, int new_data)
{
	// allocate node	
	if( (*head_ref) == NULL){
		(*head_ref) = new Node();
		(*head_ref)->data=new_data;
		return;
	}

	Node *temp = new Node();
	temp->data= new_data;
	temp->next = (*head_ref);
	(*head_ref) = temp; 
}

void swap(Node **head, int x, int y){
	Node *currX = (*head);
	Node *currY = (*head);
	Node *prevX = NULL;
	Node *prevY = NULL;
	while( currX -> data != x ){
		prevX = currX;
		currX = currX->next;
	}

	while( currY -> data != y ){
		prevY = currY;
		currY = currY->next;
	}

	if(prevX == NULL){
		(*head) = currY;
	}else{
		prevX -> next =currY;
	}

	if(prevY == NULL){
		(*head) = currX;
	}else{
		prevY -> next =currX;
	}

	Node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
	
}

// Driver code
int main()
{
	Node* head = NULL;
	// The constructed linked list is:
	// 1->2->3->4->5->6->7
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	reverseList(&head);

	printList(head);

}

// This code is contributed by Sania Kumari Gupta
// (kriSania804)
