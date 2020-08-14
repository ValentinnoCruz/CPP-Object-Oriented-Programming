/* 
 * File:   rainorshine.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020 5:58 PM
 * Purpose:  Rain or Shine
 */


//System Libraries
#include <iostream>
 #include <fstream>
 #include <string>
using namespace std; 

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
 
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
   ofstream outputFile;
   outputFile.open("rainorShinee.txt");

   const int MONTHS_SIZE = 3;  //month array size
   string month[MONTHS_SIZE] = {"June", "July", "August"};    // rows store months
   const int DAYS = 30;   // column store days
   char WeatherCal[MONTHS_SIZE][DAYS];    // array of chars hold weather condition
   string biggest = month[0]; // set first month as biggest rain
   
   cout << "R = rainy, C = cloudy, S = sunny" << endl;

    //with each iteration store user input and output in file
    for (int i = 0; i < MONTHS_SIZE; i++) {
     int Tot_Rain = 0;
     int Tot_Cloud = 0;
     int Tot_sunny = 0;

     outputFile << "The month of " << month[i] << " Weather Conditions" << endl;
     outputFile << "==================================================" << endl;

     for (int j = 0; j < DAYS; j++) {
       cout << "What is the weather condition for the month: " << month[i] 
            << " day " << (j+1) << endl;
       cin >> WeatherCal[i][j];
       outputFile << "Day " << (j+1) << "\t\t" << WeatherCal[i][j] << endl;
      
       //find total for each month
       if (WeatherCal[i][j] == 'R' || WeatherCal[i][j] == 'r') {
         Tot_Rain++;
       } else if (WeatherCal[i][j] == 'C' || WeatherCal[i][j] == 'c') {
         Tot_Cloud++;
       } else {
         Tot_sunny++;
       }
     }
    
    // dispay total rainy/cloudy/sunny days of each month
     outputFile << "==================================================" << endl;
     outputFile << "The total rainy days in the month of " 
                << month[i]  << " is " << Tot_Rain << endl; 
     outputFile << "The total cloudy days in the month of " 
                << month[i] << " is " << Tot_Cloud << endl; 
     outputFile << "The total sunny days in the month of " 
                << month[i] << " is " << Tot_sunny << endl << endl; 

     // find biggest rain amount of all three months
     int high = 0;
     if (Tot_Rain > high) {
       biggest = month[i];
     }
   }

   outputFile << "The month: " << biggest 
              << " has the biggest amount of rainfall." << endl;
   outputFile.close();
   return 0;  
 }
    //Initial Variables
   
    //Map/Process Inputs to Outputs

    //Display Outputs
    
    //Exit program!
 