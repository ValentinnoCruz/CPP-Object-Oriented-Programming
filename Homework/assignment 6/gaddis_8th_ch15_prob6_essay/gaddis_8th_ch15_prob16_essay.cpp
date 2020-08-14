/* 
 * File:   gaddis_8th_ch15_prob6_essay.cpp
 * Author: Valentinno Cruz
 * Created on July 24th, 2020, 08:15 AM 
 * Purpose:  Essay
 */


#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;



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

    
    cout<<"Checking 15.6 program.\n\n";
    Essay *s = new Essay(30,20,10,20);
    s->printGrade();
    
    return 0;
}

