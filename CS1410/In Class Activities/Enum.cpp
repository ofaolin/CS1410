//
//  Enum.cpp
//  CS1410
//
//  Created by Tyler Phalen on 2/8/22.
//
#include <iostream>
using namespace std;
 
enum DayOfWeek{Null, SUN, MON, TUE, WED, THU, FRI, SAT};
 
string nameDayOfWeek(DayOfWeek day){
     string d = "null";
     switch (day){
     case SUN: d = "Sunday";
          break;
     case MON: d = "Monday";
          break;
     case TUE: d = "Tuesday";
          break;
     case WED: d = "Wednesday";
          break;
     case THU: d = "Thursday";
          break;
     case FRI: d = "Friday";
          break;
     case SAT: d = "Saturday";
          break;
     default:
          break;
     }
 return d;
}
 
int main()
{
   DayOfWeek day;
    int d;
   cout << "Enter a day number (between 1 and 7): " << endl;
   cin >> d;
   day = static_cast<DayOfWeek>(d);
 
   cout << "Day of the week is " << nameDayOfWeek(day) << endl;
   return 0;
}
 

