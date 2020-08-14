/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 1st, 2020, 11:15 AM
 * Purpose: Monthly Payment Calculation "Error in Book"
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Format Library
#include <cmath>      //Math Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions
const unsigned char PERCENT=100;//Conversion to Percent

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    
    //Variable Declarations
    float   loan,   //Loan in $'s
            intRate,//Interest Rate in Percent/Month
            mnthPay,//Monthly payment in $'s
            totRePd,//Total amount repaid in $'s
            intPaid;//Interest Paid in $'s
    unsigned char nPymnts;//Number of compounding periods in Months
    
    //Variable Initialization
    loan=1.e4f;   //$10,000
    intRate=1e-2f;//1%/Month
    nPymnts=36;   //36 months

    //Mapping Process Inputs to Outputs
    float temp=pow(1+intRate,nPymnts);//(1+i)^n
    mnthPay=intRate*temp*loan/(temp-1);
    totRePd=nPymnts*mnthPay;
    intPaid=totRePd-loan;
    
    //Display Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Loan Amount:           $"<<setw(9)<<loan<<endl;
    cout<<"Monthly Interest Rate:  "<<setw(9)<<intRate*PERCENT<<"%"<<endl;
    cout<<"Number of Payments:     "<<setw(6)<<
            static_cast<int>(nPymnts)<<" months"<<endl;
    cout<<"Monthly Payment:       $"<<setw(9)<<mnthPay<<endl;
    cout<<"Amount Paid Back       $"<<setw(9)<<totRePd<<endl;
    cout<<"Interest Paid          $"<<setw(9)<<intPaid<<endl;
 
    //Clean Up

    //Exit stage right!
    return 0;
}