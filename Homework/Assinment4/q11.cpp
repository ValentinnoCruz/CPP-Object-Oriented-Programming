/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <streambuf>
#include <ios>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

struct Sale{
    char division[10];
    int quarter;
    int sales;
};

int main(int argc, char** argv) {

    Sale data[4];
    
    
    int sale;
    cout<<"Enter sale for quarter 1 - North.\n";
    cin>>sale;
    data[0].sales = sale;
    data[0].quarter = 1;
    strcpy(data[0].division, "North");
    
    cout<<"Enter sale for quarter 1 - South.\n";
    cin>>sale;
    data[1].sales = sale;
    data[1].quarter = 2;
    strcpy(data[1].division, "South");
    
    cout<<"Enter sale for quarter 1 - East.\n";
    cin>>sale;
    data[2].sales = sale;
    data[2].quarter = 3;
    strcpy(data[2].division, "East");
    
    cout<<"Enter sale for quarter 1 - West.\n";
    cin>>sale;
    data[3].sales = sale;
    data[3].quarter = 4;
    strcpy(data[3].division, "West");
    
    cout<<"Writing strct to binary file.\n";
    ofstream fout("struct.bin", ios::out | ios::binary);
    fout.write((char *)&data, sizeof(data));
    fout.close();
    cout<<"Data is successfully written";
    
    
    return 0;
}

