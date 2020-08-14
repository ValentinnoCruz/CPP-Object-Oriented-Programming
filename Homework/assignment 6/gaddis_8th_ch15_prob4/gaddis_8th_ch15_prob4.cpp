/* 
 * File:   gaddis_8th_ch15_pro4.cpp
 * Author: Valentinno Cruz
 * Created on July 24th, 2020, 11:10 PM 
 * Purpose:  PERSONAL  INFO CLASS
 */


#include <cstdlib>
#include <iostream>

using namespace std;

class Time     
{     
protected:         
    int hour;         
    int min; 
    int sec; 
public: 
    // Default constructor 
    Time() 
       { hour = 0; min = 0; sec = 0; } 

    // Constructor 
    Time(int h, int m, int s) 
       { hour = h; min = m; sec = s; } 

    // Accessor functions 
    int getHour() const 
       { return hour; } 

    int getMin() const 
       { return min; } 

    int getSec() const 
       { return sec; } 
}; 
 
class MilTime : public Time{
    int milHours;
    int milSeconds;
    
public:
    MilTime(int h, int s){
        if(h < 0 || h > 2359 || s < 0 || s > 59)
            throw "Error in input";
        else{
            milHours = h;
            milSeconds = s;
            int mins = h % 100;
            h = h /100;
            int hours = h % 100;

            hour = hours;
            min = mins;
            sec = s;
        }
    }
    
    int getHr(){
        return milHours;
    }
    int getStandHr(){
        return getHour();
    }
};

int main(int argc, char** argv) {

    MilTime * m = new MilTime(1630, 30);
    cout<<"Standard Hours:\t"<< m->getStandHr() <<endl;
    cout<<"Military Hours:\t"<<m->getHr() <<endl;
    
    return 0;
}

