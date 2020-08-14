/* 
 * File:   main.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 2:10 PM
 * Purpose: Dollar Conversions
 */

//System Libraries Here
#include <iostream>
#include<iomanip>
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here


//Program Execution Begins Here
int main(int argc, char** argv) {
    
    
    //Declare all Variables Here
    
    const double USD_TO_YEN = 98.93, 
                 USD_TO_EUROS = 0.74;
    double yen,
           euros;
            
    //Input or initialize values Here
   
    
    
    //Process/Calculations Here
    
   cout << setprecision(2) << fixed <<showpoint << endl;
   cout << "Dollar amount to Yen: " << endl;
   cin >> yen;
   cout << "$" << (yen * USD_TO_YEN) << " Yen" << endl;
   cout << "__________________________________" << endl;
   cout << "Dollar amount to Euros: " << endl;
   cin >> euros;
   cout << "Dollar amount to Euros: " << endl;
   cout << "$" << (euros * USD_TO_EUROS) << " Euros" << endl;
    
    
    //Output Located Here
   
    
    //Exit
    return 0;
}

