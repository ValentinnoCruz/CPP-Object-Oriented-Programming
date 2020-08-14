/* 
 * File:   gaddis_8th_ch16_prob4_ABSVAL.cpp
 * Author: Valentinno Cruz
 * Created on July 24th, 2020, 10:15 AM 
 * Purpose:  Essay
 */


#include <cstdlib>
#include <iostream>

using namespace std;



template <class T>
T absValue(T val){
    if(val < 0)
        return val * -1;
    return val;
}
template <class T>
T total(T values){
    T val = 0;
    T total = 0;
    cout<<"Enter "<<values<<" values.\n";
    for(int i = 0;i<values;i++){
        cin>>val;
        total += val;
    }
    return total;
}

/*
 * 
 */
int main(int argc, char** argv) {

    

 
    cout<<"Absolute Value of -3 is:\t"<<absValue(-3)<<endl;
    cout<<"Absolute Value of 5 is:\t"<<absValue(5)<<endl;
   
    cout<<"Checking 16.5.\n\n";
    int tot = total(5);
    cout << "Total = :\t"<< tot;
    
    return 0;
}

