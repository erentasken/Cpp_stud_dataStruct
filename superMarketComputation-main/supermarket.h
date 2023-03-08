#include <iostream>
#include <stdlib.h> 
#include "queue.h"
#include <time.h>
using namespace std;



//each item is 3 second to process 
//each customer requires 45 second to payment taking
// 10 items (3*10 + 45) second

class Supermarket{
    public:
    Supermarket(){
        srand(time(0));
    }
    void add_customer(int items); // items is bought item number add customer to random register
    void add_customer_smart(int items); // if item <= 5 add to express register otherwise add to re
    void simulate();
    private:
    MyQueue regular1;
    MyQueue regular2;
    MyQueue expressRegister;
};


void Supermarket::simulate(){
    int totalCustomerNum = regular1.getSize() + regular2.getSize() + expressRegister.getSize();
    int maxTime = 0;
    int time1 = 0;
    int time2 = 0;
    int time3= 0;

    while(!regular1.isEmpty()){
        time1 += ((regular1.getFront()*3) + 45);
        regular1.dequeue();
    }
    

    while(!regular2.isEmpty()){
        time2 += regular2.getFront()*3 + 45;
        regular2.dequeue();
    }

    while(!expressRegister.isEmpty()){
        time3 += expressRegister.getFront()*3 + 45; 
        expressRegister.dequeue();
    }

    cout << "\n";
    maxTime = time1;

    if(time2>maxTime){
        maxTime = time2;
    }
    if(time3 > maxTime){
        maxTime = time3;
    }
    cout << "Average waiting time is: " << (time1+time2+time3)/totalCustomerNum << endl;
    cout << "Time required to serve all customers: " << maxTime << endl;

}

void Supermarket::add_customer(int items){
    int randomNum = rand()%3 + 1;
    switch(randomNum){
        case 1:
            expressRegister.enqueue(items);
            break;
        case 2:
            regular1.enqueue(items);
            break;
        case 3:
            regular2.enqueue(items);
            break;
    }
}

void Supermarket::add_customer_smart(int items){
    if(items <= 5){
        expressRegister.enqueue(items);
    }
    else{
        if(regular1.getSize() < regular2.getSize()){
            regular1.enqueue(items);
        }
        else{
            regular2.enqueue(items);
        }
    }
}
