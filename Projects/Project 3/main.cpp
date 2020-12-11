/* 
 * File:   main.cpp
 * Author: Cruz, Valentinno 
<<<<<<< HEAD
=======
 * Created on August 05, 2021, 11:27 AM
 * Purpose: CSC_17A_14_SUMMER_Project_3_Battleship
>>>>>>> 09da2ad3b493ac25c605f1db11b18726f81eb20e
 */
/* 
 * Table x
 * place x
 * fire x
 * check method x
 * exception for validation c
 * abstract class c
 * template c
 * Problem: Destructor
 * Question: unable to resolve template based identifier
 * solution: create one more class which has class Game
 * 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <fstream>

using namespace std;

//User Libraries
#include "Game.h"
#include "AI.h"
#include "Table.h"
#include "Why.h"
//Global constant

//function prototypes
void intro();
void numTest(int);  //exception

//System Begins Here
int main(int argc, char** argv) {
    
//  intro();
  int num;
  bool invalid;
  do{
    num=0;
    invalid=false;
    //input size
    cout<<"Please enter the size of the table (8-10):";
    cin>>num;
    try{
      numTest(num);
//      cout<<"test\n";
    }
    catch(string numException){
      invalid=true;
      cout<<numException;
      
    }
  }while(invalid==true);
  why<test> a(num);
  
  //exit stage right
  return 0;
}
//table size validation (exception)
void numTest(int num){
  if(num<8 || num>10){
    string numException="ERROR: Number less than 7 or greater than 10\n";
    throw numException;
  }
}
//void intro(){
//    fstream io;
//    io.open("intro.txt", ios::in);
//    if(io.is_open()){
//        string temp;
//        while(get(io, temp))
//            cout<< temp <<endl;
//        io.close();
//    }
//}