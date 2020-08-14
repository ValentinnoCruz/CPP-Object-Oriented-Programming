/* 
 * File:   temptable.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 4:14 PM
 * Purpose: Celsius temperature table
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here
double celsius(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    
    //Declare all Variables Here
    
    //dislay table contents
   cout << "Fahrenheit to Celsius Table" << endl;
   cout << "________________________________" << endl;
   cout << "Fahrenheit\t\t" << "Celsius" << endl;
   cout << "________________________________" << endl;

    
    //Input or initialize values Here
   
    
    
    //Process/Calculations Here
    
    //iterate fahr temperature 0-20 display temp in fahrenheit & celsius
    for (int fahrenheit = 0; fahrenheit <= 20; fahrenheit++) {
        cout << setprecision(2) << fixed << showpoint;
        cout << "\t" << fahrenheit << "\t\t\t"
             << celsius(fahrenheit) << endl;
    }
    
    //Output Located Here
   
    
    //Exit
    return 0;
}

    /*Definit of celsius. Fahrenheit parameter holds fahrenheit temp. 
    *The function returns temperature in celsius.
    */
    double celsius (int fahrenheit) {
    return (1.8 * (fahrenheit + 32));
    }