//
//  movingGrid.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/8/22.
//

#include <iostream>
#include <sstream>

using namespace::std;

enum direction {N, E, S, W};

string dirName[4] {"North", "East", "South", "West"};

class character{
private:
    int xPosition = 0;
    int yPosition = 0;
    string name;
public:
    
    string getName(){
        return name;
    }
    
    void setName(string input){
        name = input;
    }
    
    void move(int distance, int direction){
        if (xPosition == 0 && yPosition == 0){
            cout << name << " steps out onto the grid..." << endl;
        }
        switch (direction) {
            case N: xPosition += distance;
                break;
            case E: yPosition += distance;
                break;
            case S: xPosition -= distance;
                break;
            case W: yPosition -= distance;
                break;
            default: cout << "Please give valid input";
                break;
        }
        
        cout << endl << "Heading to the " << dirName[direction] << ", " << name << " moves " << distance << " paces." << endl;
        
    }
    
    void getPosition(){
        stringstream position;
        position << "(" << xPosition << "," << yPosition << ")";
        
        cout << name << " is now located at " << position.str() << endl;
    }
    
    void validDirection(){
        
    }
};

int setDirection(string dir){
    int direction = -1;
    if (dir == "N" || dir == "n")
        direction = N;
    else if (dir == "E" || dir == "e")
        direction = E;
    else if (dir == "S" || dir == "s")
        direction = S;
    else if (dir == "W" || dir == "w")
        direction = W;
        
    return direction;
}

bool validDir(string input){
    bool valid = false;
    if (input == "N" || input == "E" || input == "S" || input == "W" || input == "n" || input == "e" || input == "s" || input == "w")
        valid = true;
    else
        cout << "Please give a valid direction." << endl;
    return valid;
}

bool validDis(int input){
    bool valid = false;
    if (input >= 0)
        valid = true;
    else
        cout << "Please give a valid distance." << endl;
    return valid;
}

int main(){
    bool valid = false;
    bool keepGoing = true;
    bool valid2 = true;
    
    character moverPerson;
    string inputStr;
    int direction = -1;
    int distance = 0;
    
    cout << "Welcome to the Grid!" << endl;
    cout << "Give your character a name: ";
    cin >> inputStr;
    moverPerson.setName(inputStr);

    do {
        while (valid == false) {
            cout << "Pick a direction (N, E, S, W): ";
            cin >> inputStr;
            valid = validDir(inputStr);
            if (valid == true)
                direction = setDirection(inputStr);
        }
        
        valid = false;
        
        while (valid == false){
            cout << "How many spaces would you like to move? ";
            cin >> inputStr;
            try {
                distance = stoi(inputStr);
            } catch (...) {
                cout << "Please provide a valid distance." << endl;
                valid2 = false;
            }
            if (valid2 == true)
                valid = validDis(distance);
            valid2 = true;
        }
        
        if (valid == true){
            moverPerson.move(distance, direction);
            moverPerson.getPosition();
        }
        
        cout << endl << "Would you like to go again? (y or n): ";
        cin >> inputStr;
        if (inputStr == "n") {
            keepGoing = false;
            cout << "Goodbye" << endl;
        } else
            valid = false;
    } while (keepGoing == true);
        


    
    
    return 0;
}
