#include <iostream>
#include "genDLList.h"
#include <string>

using namespace std;

////// My goldenstring function
bool goldenString(const string str){
	char firstChar, lastChar;
	int flag = 0;
	DLStack <char>stack;
	for( char i : str){
		if( !flag ){
			firstChar = i;
			flag = 1;
		}
		stack.push(i);
	}

	lastChar = stack.top();

	char vowels[] = {'a','e','i','o','u'};

	for( char i : vowels){
		if( i == firstChar || i == lastChar){
			return 0;
		}
	} 
	return 1;
};
////// My cheeckParantheses function

bool checkParantheses( const string str){
	DLStack<char> tempStack;
	for( char i : str){
		if(tempStack.IsEmpty()){
			tempStack.push(i);
		}
		else if( (tempStack.top() == '(' && i == ')')||(tempStack.top() == '[' && i == ']')||(tempStack.top() == '{' && i == '}')){
					tempStack.pop();
				  }
		else{
			tempStack.push(i);
		};
	}

	if(tempStack.IsEmpty()){
		return 1;
	}
	return 0;
}



int main() {
	
	string str = "neren";

	string str2 = "{[]]]}}}}";

	if (goldenString(str))
	    cout << "golden string"<<endl;
	else 
	    cout << "not a golden string"<<endl;

	if(checkParantheses(str2))
		cout << "true" << endl; 
	else
		cout << "false" << endl; 

}
