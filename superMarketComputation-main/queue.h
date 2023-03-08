#include "genDLList.h"



class MyQueue{
	private:
	int size = 0;
	DoublyLinkedList<int> queue;
	public:
	
	MyQueue():size(0){}
	bool enqueue(int el)  // add to tail
	{
		if(el){
			size++;
			queue.addToDLLTail(el);
			return 1;
		}
		return 0;

	};
	
	bool dequeue() //delete the element in the front
	{
		if(queue.isEmpty()){
			return 0;
		}
		else{
			size--;
			queue.deleteFromDLLHead();
			return 1;
		
		}
	}
	int getFront() //return the element in the front 
	{
		if(queue.isEmpty()){
			return 0;
		}
		else{
			return queue.firstEl();
		}
	}

	
	bool isEmpty()
	{
		return queue.isEmpty();	
	}

	
	int getSize(){
		return size;
	}
	
	
};