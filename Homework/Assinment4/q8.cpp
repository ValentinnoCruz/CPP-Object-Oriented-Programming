/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: Administrator
 *
 * Created on July 12, 2020, 6:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#define SIZE 10

using namespace std;

/*
 * 
 */

void arrayToFile(int * arr, int size,const char * name){
    ofstream fout(name, ios::out | ios::binary);
    for(int i = 0;i<size;i++){
        fout.write((char *)&arr[i], sizeof(arr[i]));
    }
}

void fileToArray(int *& arr, int size, const char * name){
    ifstream fin(name, ios::in | ios::binary);
    arr = new int[size];
    int a;
    int i = 0;
    while(!fin.eof()){
        fin.read((char *)&a, sizeof(a));
        arr[i++] = a;
    }
    
}
int main(int argc, char** argv) {
    
    int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int *arr2; 
    
    cout<<"Writing Data to file."<<endl;
    cout<<"Array:\t";
    for(int i = 0;i<SIZE;i++){
        cout<<arr[i]<<"  "; 
    }
    
    arrayToFile(arr, SIZE, "q8out.txt");
    cout<<"\nData is successfully written to file"<<endl;
    fileToArray(arr2, SIZE, "q8out.txt");
    
    cout<<"Reading data from file to array"<<endl;
    cout<<"Array:\t";
    for(int i = 0;i<SIZE;i++){
        cout<<arr2[i]<<"  "; 
    }
    
    return 0;
}

