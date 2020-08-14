/* 
 * File:   main.cpp
 * Author: Valentinno Cruz
 * Created on July 30th, 2020, 10:43 AM 
 * Purpose:  Final
 */



#include <iostream>
#include "Prob1Random.h"
#include <time.h>
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob4SavingsAccount.h"
#include "Prob5Employee.h"

using namespace std;

int main() {
    
    cout<<"Checking question 1 .... \n\n";
    srand(time(0));
    char n = 5;
    char rndseq[] = { 18,33,56,79,126 };
    int ntimes = 100000;
    Prob1Random a(n, rndseq);
    for (int i = 1; i <= ntimes; i++)
    {
            a.randFromSet();
    }
    int* x = a.getFreq();
    char* y = a.getSet();
    for (int i = 0; i < n; i++)
    {
            cout << int(y[i]) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getNumRand() << endl;
    
    cout<<"Checking question 2 .... \n\n";
    cout << "The start of Problem 2, the sorting problem" << endl;
    Prob2Sort<char> rc;
    bool ascending = true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char* ch2 = new char[10 * 16];
    char* ch2p = ch2;
    while (infile.get(*ch2)) { cout << *ch2; ch2++; }
    infile.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin >> column;
    char* zc = rc.sortArray(ch2p, 10, 16, column, ascending);
    for (int i = 0; i < 10; i++)
    {
            for (int j = 0; j < 16; j++)
            {
                    cout << zc[i * 16 + j];
            }
    }
    delete[]zc;
    cout << endl;
    
    cout<<"Checking question 3 .... \n\n";
    
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int* naugT = tab.getTable();
    for (int i = 0; i < rows; i++)
    {
            for (int j = 0; j < cols; j++)
            {
                    cout << naugT[i * cols + j] << " ";
            }
            cout << endl;
    }
    cout << endl;
    const int* augT = tab.getAugTable();
    for (int i = 0; i <= rows; i++)
    {
            for (int j = 0; j <= cols; j++)
            {
                    cout << augT[i * cols + j] << " ";
            }
            cout << endl;
    }
        
        
    cout<<"Checking question 4 .... \n\n";
    
    SavingsAccount mine(-300);

    for (int i = 1; i <= 10; i++)
    {
            mine.Transaction((float)(rand() % 500) * (rand() % 3 - 1));
    }
    mine.toString();
    cout << "Balance after 7 years given 10% interest = " << mine.Total((float)(0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = " << mine.TotalRecursive((float)(0.10), 7) << " Recursive Calculation " << endl;
    
    cout<<"Checking question 5 .... \n\n";
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
    Mary.toString();  
          
    
    
    
    return 0;
}