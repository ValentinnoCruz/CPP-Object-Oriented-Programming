/* 
 * File:   gaddis_8th_ch16_prob3_TEMP.cpp
 * Author: Valentinno Cruz
 * Created on July 24th, 2020, 08:15 AM 
 * Purpose:  Essay
 */


#include <cstdlib>
#include <iostream>

using namespace std;



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

/*
 * 
 */
int main(int argc, char** argv) {

    

    cout<<"Maximum between 1 and 4 is :"<<maximum(1,4) << endl;
    cout<<"Minimum between 1 and 4 is :"<<minimum(1,4) << endl;
    cout<<"Maximum between 1.1212 and 4.344 is :"<<maximum(1.1212,4.344) << endl;
    cout<<"Minimum between 1.1212 and 4.344 is :"<<minimum(1.1212,4.344) << endl;
    

    
    return 0;
}

