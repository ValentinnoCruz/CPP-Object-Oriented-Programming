/* 
 * File:   Table.cpp
 * Author: Cruz, Valentinno 
<<<<<<< HEAD
=======
 * Created on August 05, 2021, 11:27 AM
>>>>>>> 09da2ad3b493ac25c605f1db11b18726f81eb20e
 */

#include "Table.h"
#include <iostream>
using namespace std;
Table::Table(int num){
  this->num=num;
  t = new table;
  t->fake = new char *[num];
  t->real = new char *[num];
  for(int i=0;i<num;i++){
    t->fake[i] = new char[num];
    t->real[i] = new char[num];
  }
  for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
      t->fake[i][j]=' ';
      t->real[i][j]=' ';
    }
  }
}
Table::~Table(){
  for (int i=0;i<num;i++){
         delete[] t->fake[i];
         delete[] t->real[i];
    }    
    delete[] t->fake;
    delete[] t->real;
    delete t;
}
