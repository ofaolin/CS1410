//
//  movingGridV2.1.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/10/22.
//

#include <iostream>
#include <sstream>

using namespace::std;

enum direction {null, N, E, S, W};

string dirName[5] {"Null", "North", "East", "South", "West"};

struct character{
    int xPosition = 0;
    int yPosition = 0;
};

void move(character& person, int direction){
    switch (direction) {
        case N: person.xPosition += 1;
            break;
        case E: person.yPosition += 1;
            break;
        case S: person.xPosition -= 1;
            break;
        case W: person.yPosition -= 1;
            break;
        default: cout << "Please give valid input";
            break;
    }
}
void printPosition(character person){
    stringstream position;
    position << "(" << person.xPosition << "," << person.yPosition << ")";
    cout << position.str() << endl;
}
int main(){
    int input = 0;
    
    character moverPerson;
    
    
    cout << "Welcome to the Grid!" << endl;
    
    while (input != 5) {
        cout << "1: North" << endl;
        cout << "2: East" << endl;
        cout << "3: South" << endl;
        cout << "4. West" << endl;
        cout << "5. Quit" << endl;
        cout << "Pick a direction: ";
        cin >> input;
        if (input > 0 && input < 5){
            move(moverPerson, input);
            printPosition(moverPerson);
        }
        else if (input == 5)
            break;
        else
            cout << "Please make a valid selection." << endl;
    }
    
}
