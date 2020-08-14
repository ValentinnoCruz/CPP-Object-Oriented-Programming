/* 
 * File:   gaddis_8th_ch15_prob1_employee.cpp
 * Author: Valentinno Cruz
 * Created on July 24th, 2020, 04:45 PM 
 * Purpose:  Essay
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
   
 



int main(int argc, char** argv) {

    cout<<"Checking 15.1 program,\n\n";
    cout<<"Creating Production worker object.\n";
    
    ProductionWorker *e = new ProductionWorker("John", 123, "12-12-2020", 1, 1.76);
    e->print();
    

    return 0;
}

