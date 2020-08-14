/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 25th, 2020, 10:14 AM
 * Purpose:  Homework 1 Problem Energy Drink Statistics
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    unsigned short custSrv,//Number of Customers Surveyed 
                   enrgDrk,//Number of Energy Drinkers
                   citrsDk;//Number of Citrus Drinkers
    float pEnrgDk,//Percentage Energy Drinkers from those surveyed 
          pCitDrk;//Percentage of Citrus Drinkers from those surveyed
    float halfPrs;//For rounding purposes will use 1/2 a person
    
    //Initialize all known variables
    custSrv=16500;  //Number of Customer Surveyed  
    pEnrgDk=0.15f;  //Percentage 15%
    pCitDrk=5.8e-1f;//Percentage 58%
    halfPrs=0.5f;   //Half a person
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    enrgDrk=pEnrgDk*custSrv+halfPrs;//Roundup for those calculations >0.5
    citrsDk=pCitDrk*enrgDrk+halfPrs;//Roundup for those calculations >0.5
    
    //Display the Inputs/Outputs
    cout<<"Number of Customers Surveyed = "<<custSrv<<endl;
    cout<<"Number of Energy Drinkers    =  "<<enrgDrk<<endl;
    cout<<"Number of Citrus Drinkers    =  "<<citrsDk<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}