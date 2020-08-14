/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on July 26, 2020, 3:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/*
 * 
 */
//For 15.1
class Employee{
protected:
    string name;
    int no;
    string date;
    
public:
    Employee(string name, int no, string date) :
    name(name), no(no), date(date) {}
    virtual void print() = 0;
};

class ProductionWorker : public Employee{
public:
    ProductionWorker(string name, int no, string date, int shift, double rate) :
    Employee(name, no, date), shift(shift), rate(rate) {
    }

    int shift;
    double rate;
    
    void print(){
        cout<<"Name:\t"<<name<<endl;
        cout<<"Number:\t"<<no<<endl;
        cout<<"Date:\t"<<date<<endl;
        cout<<"shift:\t"<<shift<<endl;
        cout<<"Hourly Rate:\t"<<rate<<endl;
    }
    
    
    
};


class GradedActivity     
{     
private:        
    double score; // To hold the numeric score 
public: 
      // Default constructor 
    GradedActivity() 
       { score = 0.0; } 

    // Constructor 
    GradedActivity(double s) 
       { score = s; } 

    // Mutator function 
    void setScore(double s) 
       { score = s; } 

    // Accessor functions 
    double getScore() const 
       { return score; } 

    char getLetterGrade(){
      char letterGrade; // To hold the letter grade 

      if (score > 89) 
         letterGrade = 'A'; 
      else if (score > 79) 
         letterGrade = 'B'; 
      else if (score > 69) 
         letterGrade = 'C'; 
      else if (score > 59) 
         letterGrade = 'D'; 
      else 
         letterGrade = 'F'; 

      return letterGrade; 
    } 
   }; 
   
 

//For 15.6
class Essay : public GradedActivity{
    int grammer;
    int spelling;
    int len;
    int content;
public:
    Essay(int grammer, int spelling, int len, int content) :
    GradedActivity(), grammer(grammer), spelling(spelling), len(len), content(content) {
    }
    
    void printGrade(){
        setScore(grammer+spelling+len+content);
        cout<< "Grade:\t" << getLetterGrade();
    }
};  

int main(int argc, char** argv) {

    cout<<"Checking 15.1 program,\n\n";
    cout<<"Creating Production worker object.\n";
    
    ProductionWorker *e = new ProductionWorker("John", 123, "12-12-2020", 1, 1.76);
    e->print();
    
    
    cout<<"Checking 15.4 program.\n\n";
    
    cout<<"Checking 15.6 program.\n\n";
    Essay *s = new Essay(30,20,10,20);
    s->printGrade();
    
    return 0;
}

