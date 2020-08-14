/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 11th, 2020, 7:45 PM
 * Purpose:  Stats structure specification
 */

#ifndef MDSTRUCT_H
#define MDSTRUCT_H
#include "Array.h"

struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

#endif /* MDSTRUCT_H */