//
//  Die.h
//  CS1410
//
//  Created by Tyler Phalen on 2/10/22.
//

#pragma once
#include <iostream>
using namespace std;
 
class Die{
   public:
     Die(int sides);   //Constructor
     void roll();      //Method Declaration
     void display();   //Method Declaration
     void setNumberSides(int sides);//setter Declaration
     int getDieValue();
 
   private:
     int value;
     int numSides; 
};//End Class
//Constructor, sets up the class
Die::Die(int sides): numSides(sides){
 value = 1;
}
//Method to roll the die
void Die::roll(){
 value = rand() % numSides + 1;
}
//Sets the number of sides of the die
void Die::setNumberSides(int sides){
 numSides = sides;
}
//Displays die
void Die::display(){
  cout << "-----" << endl;
  cout << "| " << value << " |" << endl;
  cout << "-----" << endl;
}
int Die::getDieValue(){
    return value;
}

