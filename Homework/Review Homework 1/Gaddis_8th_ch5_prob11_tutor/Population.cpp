/* 
 * File:   population.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 3:42 PM
 * Purpose: population of organism 
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
    
    int startNumOrgan = 0,
        Daymult = 0,
        totOrgan = 0,
        totDaily = 0;
    float DayInc = 0.00f;

  
    //Input or initialize values Here
   
    cout << "Enter starting number of organisms: ";
    cin >> startNumOrgan;
  
   
    
    //Process/Calculations Here
    
    // prompt user for the initial size of population
    while (startNumOrgan < 2) {
        cout << "Starting size of population can't be < 2. try again. ";
        cin >> startNumOrgan;
    }
    
    // find average daily increase value
    cout << "Please enter AVG daily percent increase in population: ";
    cin >> DayInc;
    
    // if value does not fit within scope prompt user to try again
    while (DayInc < 0) {
        cout << "Don't accept a negative number for average daily population increase. try again.";
        cin >> DayInc;
    }
    
    // get value for number of days 
    cout << "Enter the number of days the organisms will multiply: ";
    cin >> Daymult;

    // prompt if value is less than 1
    while (Daymult < 1) {
        cout << "Can't accept a number less than 1 for the number of days they will multiply. try again.";
        cin >> Daymult;
    }

   
            
    
    //Output Located Here
   
    totDaily = (startNumOrgan * (DayInc / 100) + startNumOrgan);

    for (int day = 1; day <= Daymult; day++) {
        totDaily = (totDaily * (DayInc / 100)) + totDaily;
        totOrgan += totDaily;
        cout << "Day " << day << " population size is " << totOrgan << "." << endl;
    }
    cout << "Estimated Population growth after " << Daymult << " days is "
         << totOrgan << "." << endl;
    
    //Exit
    return 0;
}

