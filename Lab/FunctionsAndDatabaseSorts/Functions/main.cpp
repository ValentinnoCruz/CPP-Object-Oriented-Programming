/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 23rd, 2019, 11:26 AM
 * Purpose:  Functions
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const float PERCENT=100.0f;//Conversion to percentage

//Future Value Savings Function
//Function Prototypes of Equivalent functions
float fVal_1(float,float,int);   //Power Call
float fVal_2(float,float,int);   //Exponential/Log Call
float fVal_3(float,float,int);   //For-loop
float fVal_4(float,float,int);   //Recursion
float fVal_4(float,float,float); //Name Over-ride
float fVal_5(float,float,int=12);//Defaulted Value
float fVal_6(float,float,int);   //Static Variable
void  fVal_7(float &,float,int);   //Pass by Reference Variable

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float pv,i;//Present value in $'s, Interest in %/Year
    int n;     //Number of compounding periods in years
    
    //Initialize or input i.e. set variable values
    pv=100.0f;//$100's
    n=8;//12 years
    i=72/n;//%/year by rule of 72, i.e. double the present value
 
    //Display the outputs
    cout<<"Present Value                 = $"<<pv<<endl;
    cout<<"Number of compounding periods =   "<<n<<" years"<<endl;
    cout<<"Percentage per year           =    "<<i<<" %/year"<<endl;
    cout<<"Future Value using pow()      = $"<<fVal_1(pv,i/PERCENT,n)<<endl;
    cout<<"Future Value using exp()-log()= $"<<fVal_2(pv,i/PERCENT,n)<<endl;
    cout<<"Future Value using for-loop   = $"<<fVal_3(pv,i/PERCENT,n)<<endl;
    cout<<"Future Value using recursion  = $"<<fVal_4(pv,i/PERCENT,n)<<endl;
    cout<<"Future Value same name        = $"<<fVal_4(pv,i/PERCENT,1.0f*n)<<endl;
    cout<<"Future Value using default    = $"<<fVal_5(pv,i/PERCENT)<<endl;
    cout<<"Future Value using default    = $"<<fVal_5(pv,i/PERCENT,n)<<endl;
    for(int cnt=1;cnt<=5;cnt++){
        cout<<"Future Value Static Call      = $"<<fVal_6(pv,i/PERCENT,n)<<endl;
    }
    float fv7=pv;
    fVal_7(fv7,i/PERCENT,n);
    cout<<"Future Value using reference  = $"<<fv7<<endl;
    //Exit stage right or left!
    return 0;
}

void fVal_7(float &pv,float i,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
}

float fVal_6(float pv,float i,int n){
    static int count;
    count++;
    cout<<"Static Function Count = "<<count<<endl;
    return fVal_5(pv,i,n);
}

float fVal_5(float pv,float i,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
    return pv;
}

float fVal_4(float pv,float i,float n){
    cout<<"Function Name repeated"<<endl;
    return pv*pow(1+i,n);
}

float fVal_4(float pv,float i,int n){
    if(n<=0)return pv;
    return fVal_4(pv,i,n-1)*(1+i);
}

float fVal_3(float pv,float i,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
    return pv;
}

float fVal_2(float pv,float i,int n){
    return pv*exp(n*log(1+i));
}

float fVal_1(float pv,float i,int n){
    return pv*pow(1+i,n);
}