/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on July 26, 2020, 5:09 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//For 16.1
class Date{
    int day;
    int month;
    int year;
    
public:
    Date(int day, int month, int year) :
    day(day), month(month), year(year) {
    }


};

class InvalidDay : public Date{
    
    
    InvalidDay(int day, int month, int year) :
    Date(day, month, year) {
    
        if(day < 1 || day > 32)
            throw "Day incorrect.\n";
    }


};

class InvalidMonth : public Date{

    InvalidMonth(int day, int month, int year) :
    Date(day, month, year) {
        if(month < 1 || month > 12)
            throw "Month incorrect.\n";
    }

};

//For 16.3
template <class T>
T maximum(T one, T two){
    if(one > two)
        return one;
    return two;
}
template <class T>
T minimum(T one, T two){
    if(one < two)
        return one;
    return two;
}

//For 16.4
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

    
    cout<<"Checking 16.3.\n\n";
    cout<<"Maximum between 1 and 4 is :"<<maximum(1,4) << endl;
    cout<<"Minimum between 1 and 4 is :"<<minimum(1,4) << endl;
    cout<<"Maximum between 1.1212 and 4.344 is :"<<maximum(1.1212,4.344) << endl;
    cout<<"Minimum between 1.1212 and 4.344 is :"<<minimum(1.1212,4.344) << endl;
    
    
    cout<<"Checking 16.4.\n\n";
    cout<<"Absolute Value of -3 is:\t"<<absValue(-3)<<endl;
    cout<<"Absolute Value of 5 is:\t"<<absValue(5)<<endl;
   
    cout<<"Checking 16.5.\n\n";
    int tot = total(5);
    cout << "Total = :\t"<< tot;
    
    return 0;
}

