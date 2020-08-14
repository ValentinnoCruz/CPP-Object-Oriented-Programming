/* 
 * File:   days.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 3:10 PM
 * Purpose: days to months
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    
    
    //Declare all Variables Here
    int month,
        year;

   
            
    //Input or initialize values Here
   cout << "Enter a month in numerical number" << endl;
   cin >> month;
   cout << "Enter a year" << endl;
   cin >> year;
    
    //Process/Calculations Here
    
    if (month >= 1 && month <= 12) {
        if (month == 2) {
            if ((year%100 == 0) && (year%400 == 0)) {
                cout << "29 days" << endl;
            } 
            else if (year%4 ==0) {
                cout << "29 days" << endl;
            }       
            else {
                cout << "28 days" << endl;
            }   
        } 
            else if ((month == 6) || (month == 11) || (month == 9)) {
                cout << "30 days";
            } 
            else {
                cout << "31 days";
             }
   } 
            else {
            cout << "Please enter valid month between 1- 12" << endl;
        }
    //Output Located Here
   
    
    //Exit
    return 0;
}

