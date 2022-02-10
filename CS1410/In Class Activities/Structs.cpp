//
//  Structs.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/8/22.
//

#include <iostream>
#include <sstream>
using namespace std;

enum months {Null, Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

string mon[13] = {"Null","January","February","March","April","May","June","July","August","September","October","November","December"};
 
struct Date{
   int day;
   int month;
   int year;
};
 
string dateString(Date);
 
int main()
{
    Date mlk_day = {21,1,2022};
    
    mlk_day.day = 20;
    
    mlk_day.year = 2020;
 
   cout << dateString(mlk_day) << endl;
 
   return 0;
}
 
string dateString(Date d){
    string mName;
    switch (d.month) {
        case Jan: mName = mon[Jan];
            break;
        case Feb: mName = mon[Feb];
            break;
        case Mar: mName = mon[Mar];
            break;
        case Apr: mName = mon[Apr];
            break;
        case May: mName = mon[May];
            break;
        case Jun: mName = mon[Jun];
            break;
        case Jul: mName = mon[Jul];
            break;
        case Aug: mName = mon[Aug];
            break;
        case Sep: mName = mon[Sep];
            break;
        case Oct: mName = mon[Oct];
            break;
        case Nov: mName = mon[Nov];
            break;
        case Dec: mName = mon[Dec];
            break;
        default: mName = mon[Null];
            break;
    }
 stringstream sstream;
 sstream << d.day << " ";
 sstream << mName << " ";
 sstream << d.year;
 
 return sstream.str();
}

