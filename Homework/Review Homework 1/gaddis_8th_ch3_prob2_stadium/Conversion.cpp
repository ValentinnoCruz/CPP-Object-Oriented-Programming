/* 
 * File:   main.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 1:42 PM
 * Purpose: 3.12 Celsius Conversion
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
    
    float cent,      // variable for celsius 
          fahr;     // variable for fahrenheit
          
            
    //Input or initialize values Here
    
    cout<< " What is the Temperature in Celsius" <<endl;
    cin >> cent;                 // User input  value
    
    
    //Process/Calculations Here
    
    fahr = 9/5.0*cent + 32;     // Conversion from Celsius to Fahrenheit 
    
    //Output Located Here
   
    cout << cent << " The degrees Celsius will be " << fahr;
    cout << " Degrees Fahrenheit " << endl;
    
    //Exit
    return 0;
}

