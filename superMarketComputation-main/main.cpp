#include <iostream>
#include <stdlib.h> 
#include "supermarket.h"
using namespace std;

int main(){

	Supermarket m1;
	Supermarket m2;

	
		m1.add_customer(4);
		m2.add_customer_smart(11);
		m1.add_customer(4);
		m2.add_customer_smart(11);
		m1.add_customer(4);
		m2.add_customer_smart(11);
	

	cout << "Results for supermarket 1: \n ----------------" << endl; 
	m1.simulate();
	cout << "Results for supermarket 2: \n ----------------" << endl; 
	m2.simulate();

}