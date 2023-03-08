#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person{
    public:
    Person(string name = " ", int age = 0){
        storedName = name;
        storedAge = age;
    };
    int storedAge;
    string storedName;
    Person* nextAge = nullptr;
    Person* nextName = nullptr;
};

Person *ageHead; // data base starting point.
Person *nameHead;

void loadfile(string filename){
    string name;
    int age;
    fstream file(filename, ios::app | ios::in | ios::out); // ios::in is for reading the database
    // initializing the linked list 
    file >> name ; file >> age;
    ageHead = new Person(name,age);
    while(!file.eof()){
        file >> name ; file >> age;
        Person* newperson = new Person(name, age);
        {
        Person *prev = nullptr;
        Person* iter;        
            for(iter = ageHead; iter; iter = iter->nextAge){
                if(ageHead->storedAge > newperson->storedAge){
                    newperson->nextAge = ageHead;
                    ageHead = newperson;
                    break;
                }
                else if(iter->storedAge > newperson->storedAge){
                    prev->nextAge = newperson;
                    newperson->nextAge = iter;
                    break;
                }
                prev = iter;
            }
            if(iter == nullptr && age > prev->storedAge) prev->nextAge = newperson;
        }
    }
    nameHead = ageHead;
    Person* prev = nullptr;
    Person* nameIter;
    for(Person* iter = ageHead; iter ; iter = iter->nextAge){
        for(nameIter = nameHead; nameIter ; nameIter= nameIter->nextName){
            if(nameHead->storedName > iter->storedName){
                iter->nextName = nameHead;
                nameHead = iter;
                break;
            }
            else if(nameIter->storedName > iter->storedName){
                prev->nextName = iter;
                iter->nextName = nameIter;
                break;                
            }
            prev = nameIter;
        }
        if(nameIter == nullptr && iter->storedName > prev->storedName) prev->nextName = iter;
    }
    file.close();
}

void add(string name, int age){
    Person* newperson = new Person(name, age);
    {
    Person *prev = nullptr;
    Person* iter;        
        for(iter = ageHead; iter; iter = iter->nextAge){
            if(ageHead->storedAge > newperson->storedAge){
                newperson->nextAge = ageHead;
                ageHead = newperson;
                break;
            }
            else if(iter->storedAge > newperson->storedAge){
                prev->nextAge = newperson;
                newperson->nextAge = iter;
                break;
            }
            prev = iter;
        }
        if(iter == nullptr && age > prev->storedAge) prev->nextAge = newperson;
    }
    Person* prev = nullptr;
    Person* nameIter;
    for(nameIter = nameHead; nameIter ; nameIter= nameIter->nextName){
        if(nameHead->storedName > newperson->storedName){
            newperson->nextName = nameHead;
            nameHead = newperson;
            break;
        }
        else if(nameIter->storedName > newperson->storedName){
            prev->nextName = newperson;
            newperson->nextName = nameIter;
            break;                
        }
        prev = nameIter;
    }
    if(nameIter == nullptr && newperson->storedName > prev->storedName) prev->nextName = newperson;
}

bool Remove(string name){
    Person* prev = nullptr;
    int age;
    for(Person *nameiter = nameHead ; nameiter; nameiter = nameiter->nextName){
        if(nameHead->storedName == name){
            age = nameHead->storedAge;
            nameHead = nameHead->nextName;
            for(Person *ageiter = ageHead; ageiter; ageiter = ageiter ->nextAge){
                if(ageHead->storedAge == age){
                    ageHead = ageHead->nextAge;
                    break;
                }
            }
        }
        else if(nameiter->storedName == name){
            age = nameiter->storedAge;
            prev->nextName = nameiter->nextName;
            Person *prev1 = nullptr;
            for(Person* ageiter = ageHead ; ageiter; ageiter = ageiter->nextAge){
                if(ageHead->storedAge == age){
                    ageHead = ageHead->nextAge;
                    break;
                }
                else if(ageiter->storedAge == age){
                    prev->nextAge = ageiter->nextAge;
                    break;
                }
                prev = ageiter;
            }
            return 1;          
        }
        prev = nameiter;
    }
    return 0;
}

void update(string name, int age){
    int ageFinder;
    Person *prev = nullptr;
    Person *prev1 = nullptr;
    for(Person *iter = nameHead; iter; iter = iter->nextName){
        if(iter->storedName == name){
            ageFinder = iter->storedAge;
            for(Person *ageiter = ageHead; ageiter; ageiter = ageiter->nextAge){
                if(ageiter->storedAge == ageFinder){
                    Person *iterr;
                    for(iterr = ageHead; iterr; iterr = iterr->nextAge){
                        if(ageHead->storedAge > age){
                            prev->nextAge = ageiter->nextAge;
                            ageiter->nextAge = ageHead;
                            ageHead = ageiter;
                            ageiter->storedAge = age;
                            break;
                        }
                        else if(iterr->storedAge > age){
                            prev1->nextAge = ageiter;
                            ageiter->nextAge = iterr;
                            ageiter->storedAge = age;
                            break;
                        }
                        prev1 = iterr;
                    }
                    if(iterr == nullptr && prev1->storedAge < age){
                        prev1->nextAge = ageiter;
                        ageiter->nextAge = nullptr;
                        ageiter->storedAge = age;
                        break;
                    }
                }
                prev = ageiter;
            }
        }
    }
}

void printByAge(){
    for(Person* iter = ageHead ; iter; iter = iter->nextAge) cout << iter->storedAge << " ";
    cout << "\n";
}

void printByName(){
    for(Person* iter = nameHead ; iter ; iter = iter->nextName) cout << iter->storedName << " ";
    cout << "\n";
}

void saveToFileByName(string filename){
    ofstream file(filename, ios::app | ios::out | ios::in);
    for(Person* iter = nameHead; iter ; iter = iter->nextName){
        file << iter->storedName << "\n";
    }
    file.close();    
}
void saveToFileByAge(string filename){
    ofstream file(filename, ios::app | ios::out | ios::in);
    for(Person* iter = ageHead ; iter ; iter = iter->nextAge){
        file << iter->storedAge << "\n";
    }
    file.close();
}

int main(){
    // !!!! nameHead is for sorted linked list's head for names. Use it with ->storedName for reaching the list items.
    
    // !!!! ageHead is for sorted linked list's head for ages. ->storedAge for reaching the list items.

    // !!!! Remove function's first character is upper case !! BE CAREFUL
    
    loadfile("database.txt");

    //Below this comment I tested my code 
    printByAge();
    printByName();
    cout << "\n";
    add("derin", 40);
    printByAge();
    printByName();
    cout << "\n";
    update("ahmet",15);
    printByAge();
    printByName();
    cout << "\n";
    Remove("ferzan");
    printByAge();
    printByName();
    saveToFileByAge("age.txt");
    saveToFileByName("name.txt");

    return 0;
}

