#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void announcement( int i, int userChoice){
        switch(userChoice){
            case 1:
                cout << "\nClass type = first-class\nSeat number: "<< i+1<<"\n###################################################\n"<<endl;
                break;
            case 2:
                cout << "\nClass type = economy-class\nSeat number: "<< i+1<<"\n#################################################\n"<<endl;
                break;
        }
}

int economySetter(int seats[], int *counterEconomy){
    bool flag = 0;
    int rand = random(5,9);
    int preValue;

    while(true){
        if(seats[rand] != 1){
            (*counterEconomy)++;
            seats[rand] = 1;
            announcement(rand, 2);
            flag = 1;
            preValue = rand;
            if(*counterEconomy == 5){
                cout << "All seats have been occupied.\nNext flight leaves in 3 hours";
                exit(0);
            }
            return 1;
        }else{
            while(rand == preValue);{
                rand = random(5,9);
            }
            continue;
    }
    return -1;
}}

int firstClassOccupied(int seats[], int *counterEconomy){
    label: cout <<"first-class is full would you like to reserve a seat on economy-class ? (yes / no): " ; 
    string condition;
    cin >> condition;
    if( condition == "yes") {
        economySetter(seats, counterEconomy);
    }else if(condition == "no"){
        cout << "All seats have been occupied.\nNext flight leaves in 3 hours";
        exit(0);
    }else{
        cout << "Please type proper answer. "<< "\n" << endl;
        goto label;
    }
    return -1;
}

int firstClassSetter( int seats[], int *counterFirst, int *counterEconomy){
    bool flag = 0;
    int rand = random(0,4);
    int preValue;

    while(true){
        if(seats[rand] != 1){
            (*counterFirst)++;
            seats[rand] = 1;
            announcement(rand, 1);
            flag = 1;
            preValue = rand;
            if(*counterFirst == 5){
                firstClassOccupied(seats, counterEconomy);
            }
            return 1;
        }else{
            while ( rand == preValue );{
                rand = random(0,4);
            } 
            continue;
        }
    }
    if(flag == 0) {
        firstClassOccupied(seats, counterEconomy);
    }
    return -1;
}

int main(){
    int userChoice;
    int seats[10] = {0,0,0,0,0,0,0,0,0,0};
    int counterFirst = 0;
    int counterEconomy = 0;
    while(true){

        cout << "Please type 1 for first-class" << endl;
        cout << "Please type 2 for economy-class" << endl;
        cout << "Enter number: ";
        cin >> userChoice;

        if( userChoice == 1 ){ // it will pick in between 1 and 5 
           firstClassSetter(seats,&counterFirst, &counterEconomy);
        }else if(userChoice == 2){ // it will pick in between 6 and 10 
           economySetter(seats, &counterEconomy);
        }else{
            cout << "Not a valid class type.";
            continue;
        }
        //some kind of changes
    }
    return 0;
    }