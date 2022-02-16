//
//  test.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/13/22.
//

#include <iostream>
using namespace std;

void incrementDos(int &x){
    x += 2;
    
}

int main(){
    int var = 1;
    
    cout << var << endl;
    
    incrementDos(var);
    
    cout << var;
}
