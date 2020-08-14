/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on July 23, 2020, 2:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <memory> 
#include <math.h>

using namespace std;

class NumDays{
    int hours;
    float days;
public:
    
    NumDays(int h){
        hours = h;
        days = (float) hours / 8.0;
    }
    
    print(){
        cout<<"Hours:\t"<<hours<<endl;
        cout<<"Days:\t"<<days<<endl;
    }
    NumDays(){
        
    }
    NumDays operator ++(int){
        NumDays temp;
        NumDays old;
        old = *this;
        temp.hours = this->hours+1;
        temp.days = (float)temp.hours / 8.0;
        
        *this = temp;
        return old;
    }
    NumDays operator --(int){
        NumDays temp;
        NumDays old;
        old = *this;
        temp.hours = this->hours-1;
        temp.days = (float)temp.hours / 8.0;
        
        *this = temp;
        return old;
    }
    NumDays operator ++(){
        NumDays temp;
        
        
        temp.hours = this->hours+1;
        temp.days = (float)temp.hours / 8.0;
        
        *this = temp;
        return temp;
    }
    NumDays operator --(){
        NumDays temp;
        
        
        temp.hours = this->hours-1;
        temp.days = (float)temp.hours / 8.0;
        
        *this = temp;
        return temp;
    }
    NumDays operator +(NumDays & obj){
        this->hours += obj.hours;
        this->days = (float)this->hours / 8.0;
        
        return *this;
    }
    NumDays operator -(NumDays & obj){
        this->hours -= obj.hours;
        this->days = (float)this->hours / 8.0;
        
        return *this;
    }
};

class DayOfYearModified{
    
    string month;
    int no;
public:
    DayOfYearModified(string s,int n){
        if(s.compare("February") == 0 && n > 28){
            cout<<"Error initializing values.\n";
        }
        else if(((s.compare("April") == 0) || (s.compare("June") == 0) || (s.compare("September") == 0) ||(s.compare("November") == 0)) && n > 30){
            cout<<"Error initializing values.\n";
        }
        else{
            month = s;
            no = n;
        }
    }
    DayOfYearModified(){
        
    }
    //Postfix
    DayOfYearModified operator++(int) 
    { 
        DayOfYearModified temp; 
        DayOfYearModified old = *this;
        if(no == 31 && month.compare("December") == 0){
            temp.month = "January";
            temp.no = 1;
        }
        else{
            temp.month = this->month;
            temp.no = this->no+1;
        }
        *this = temp;
        return old; 
    }
    DayOfYearModified operator--(int) 
    { 
        DayOfYearModified temp; 
        DayOfYearModified old = *this;
        if(no == 1 && month.compare("January") == 0){
            temp.month = "December";
            temp.no = 31;
        }
        else{
            temp.month = this->month;
            temp.no = this->no-1;
        }
        *this = temp;
        return old; 
    }
    DayOfYearModified operator++() 
    { 
        DayOfYearModified temp; 
        
        if(no == 31 && month.compare("December") == 0){
            temp.month = "January";
            temp.no = 1;
        }
        else{
            temp.month = this->month;
            temp.no = this->no+1;
        }
        *this = temp;
        return temp; 
    }
    DayOfYearModified operator--() 
    { 
        DayOfYearModified temp; 
        
        if(no == 1 && month.compare("January") == 0){
            temp.month = "December";
            temp.no = 31;
        }
        else{
            temp.month = this->month;
            temp.no = this->no-1;
        }
        *this = temp;
        return temp; 
    }
    void print(){
        cout<<month<<" "<<no<<endl;
    }
};

class DayOfYear{
private:
    int n;
    string months[12] = {"January", "February", "March", "April","May","June","July","August","September","October","November","December"};
   
public:
    DayOfYear(int no){
        n = no;
    }
    void print(){
        if(n >= 1 && n <- 31)
            cout<<months[0]<< n;
        else if(n > 31 && n <= 59)
            cout<<months[1]<<31-n;
        else if(n > 59 && n <= 90)
            cout<<months[2]<<59-n;
        else if(n > 90 && n <= 120)
            cout<<months[3]<<90-n;
        else if(n > 120 && n <= 151)
            cout<<months[4]<<120-n;
        else if(n > 151 && n <= 181)
            cout<<months[5]<<151-n;
        else if(n > 181 && n <= 212)
            cout<<months[6]<<181-n;
        else if(n > 212 && n <= 243)
            cout<<months[7]<<212-n;
        else if(n > 243 && n <= 273)
            cout<<months[8]<<243-n;
        else if(n > 273 && n <= 304)
            cout<<months[9]<<273-n;
        else if(n > 304 && n <= 334)
            cout<<months[10]<<304-n;
        else if(n > 334 && n <= 365)
            cout<<months[11]<<334-n;
        
    }

};

class Number{
private:
    int number;
    string lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen" ,"seventeen" , "eighteen", "nineteen"};
    

public:
    Number(int n){
        number = n;
    }
    
    void print(){
        int digit = 0;
        int temp = number;
        while(temp != 0){
            digit++;
            temp = temp/10;
        }
        temp = number;
        int first = 0, second = 0, third = 0, fourth = 0;
        if(digit == 4){
            fourth = temp%10;
            temp = temp/10;
            third = temp%10;
            temp = temp/10;
            second = temp%10;
            temp = temp/10;
            first = temp%10;
            
            cout<<lessThan20[first]<<" thousand ";
            if(second != 0){
                cout<<lessThan20[second]<<" hundred ";
            }
            if(third != 0){
                int n = third * 10;
                n = n+fourth;
                cout<<lessThan20[n];
            }
            else{
                cout<<lessThan20[fourth];
            }
            
        }
        else if(digit == 3){
            third = temp%10;
            temp = temp/10;
            second = temp%10;
            temp = temp/10;
            first = temp%10;
            if(first != 0){
                cout<<lessThan20[first]<<" hundred ";
            }
            if(second != 0){
                int n = second * 10;
                n = n+third;
                cout<<lessThan20[n];
            }
            else{
                cout<<lessThan20[third];
            }
        }
        else if(digit == 2){
            second = temp%10;
            temp = temp/10;
            first = temp%10;
            if(first != 0){
                int n = first * 10;
                n = n+second;
                cout<<lessThan20[n];
            }
            else{
                cout<<lessThan20[second];
            }
        }
        else if(digit == 1){
            first = temp%10;
            cout<<lessThan20[first];
        }
           
        
    }
};

 

class Demo{
    

 public:
	 Demo(){
             cout << "Welcome to the constructor!\n";
         }
};



class Rectangle
{
    private:
    double width;
    double length;
    public:
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    void setLength(double length) {
        this->length = length;
    }

    void setWidth(double width) {
        this->width = width;
    }

    double getArea() const{
        return width * length;
    }
    
};

int main(int argc, char** argv) {
    /*Rectangle box; // Define an instance of the Rectangle class
    double rectWidth; // Local variable for width
    double rectLength; // Local variable for length
    cout<<"Testing Problem 13.1........................."<<endl;
    cout<<"Checkpoint 13.1 is false as you can declare private members even after public ones.\n";
    // Get the rectangle's width and length from the user.
    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? ";
    cin >> rectLength;

    // Store the width and length of the rectangle
    // in the box object.
    box.setWidth(rectWidth);
    box.setLength(rectLength);

    // Display the rectangle's data.
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;
    
    
    
    cout<<"Testing Problem 13.4........................."<<endl;
    cout<<"Checkpoint 13.4 correct option is C\n";

    double number; // To hold a number
    double totalArea; // The total area

    // Dynamically allocate the objects.
    Rectangle* kitchen = new Rectangle();
    Rectangle* bedroom = new Rectangle();
    Rectangle* den = new Rectangle();

    // Get the kitchen dimensions.
    cout << "What is the kitchen's length? ";
    cin >> number; // Get the length
    kitchen->setLength(number); // Store in kitchen object
    cout << "What is the kitchen's width? ";
    cin >> number; // Get the width
    kitchen->setWidth(number); // Store in kitchen object

    // Get the bedroom dimensions.
    cout << "What is the bedroom's length? ";
    cin >> number; // Get the length
    bedroom->setLength(number); // Store in bedroom object
    cout << "What is the bedroom's width? ";
    cin >> number; // Get the width
    bedroom->setWidth(number); // Store in bedroom object

    // Get the den dimensions.
    cout << "What is the den's length? ";
    cin >> number; // Get the length
    den->setLength(number); // Store in den object
     cout << "What is the den's width? ";
     cin >> number; // Get the width
     den->setWidth(number); // Store in den object

     // Calculate the total area of the three rooms.
     totalArea = kitchen->getArea() + bedroom->getArea() +
     den->getArea();


     // Display the total area of the three rooms.
     cout << "The total area of the three rooms is "
     << totalArea << endl;
     
    
    cout<<"Testing Problem 13.5........................."<<endl;
    cout<<"Checkpoint 13.5 correct option is C\n";
    
    Rectangle box; // Define an instance of the Rectangle class
    double rectWidth; // Local variable for width
    double rectLength; // Local variable for length

    // Get the rectangle's width and length from the user.
    cout << "This program will calculate the area of a\n";
    cout << "rectangle. What is the width? ";
    cin >> rectWidth;
    cout << "What is the length? ";
    cin >> rectLength;


    box.setWidth(rectWidth);
    box.setLength(rectLength);

    // Display the rectangle's data.
    cout << "Here is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;
    
    
    cout<<"\n\nTesting Problem 13.6........................."<<endl;
    cout<<"Checkpoint 13.6: Members are declared private so that they should not be accessed from outside the class.\n";
    
    Demo demoObject; // Define a Demo object;
 
    cout << "This program demonstrates an object\n";
    cout << "with a constructor.\n";
    
     
    
    
    
    cout<<"\n\nTesting Problem 14.1........................."<<endl;
    cout<<"Enter the number between 0 and 9999:\t";
    int n;
    cin>>n;
    
    Number no(n);
    no.print();
    
    
    
    cout<<"\n\nTesting Problem 14.2........................."<<endl;
    int a;
    cout<<"Enter the number between 1 and 365:\t";
    cin>>a;
    DayOfYear obj(a);
    obj.print();
    
    
    cout<<"\n\nTesting Problem 14.3........................."<<endl;
    DayOfYearModified obj("January", 1);
    cout<<"Current Value:\t";
    obj.print();
    cout<<"Testing postfix ++\nValue:\t";
    obj++;
    obj.print();
    cout<<"Testing postfix --\nValue:\t";
    obj--;
    obj.print();
    return 0;
    */
    
    
    cout<<"\n\nTesting Problem 14.4........................."<<endl;
    NumDays obj1(8);
    NumDays obj2(16);
    cout<<"First Object:\n";
    obj1.print();
    cout<<"Second Object:\n";
    obj2.print();
    
    cout<<"After adding both objects:\n";
    obj1 = obj1 + obj2;
    obj1.print();

}

