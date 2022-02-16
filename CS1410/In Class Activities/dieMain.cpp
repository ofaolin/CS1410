//
//  Die.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/10/22.
//

#include <iostream>
#include <time.h>
#include "Die.h"
using namespace std;
 
int main() {
    srand(time(NULL));  //Set the random seed
    //Declare die
    Die d1(20);
    //Call methods
    d1.roll();
    d1.display();
    
    Die d2(20);
    d2.roll();
    d2.display();
    
    if (d1.getDieValue() == d2.getDieValue())
        cout << "Doubles!" << endl;
}

