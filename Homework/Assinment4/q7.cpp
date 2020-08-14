/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on July 12, 2020, 6:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    char file1[80];
    char file2[80];
    char buffer[80];
    
    cout<<"Enter first file name:\t"<<endl;
    cin>>file1;
    cout<<"Enter second file name:\t"<<endl;
    cin>>file2;
    
    
    ifstream fin(file1);
    ofstream fout(file2);
    
    while(!fin.eof()){
        fin.getline(buffer, 80, '\n');
        for(int i = 0;buffer[i] != '\n';i++){
            if(i == 0 && buffer[i] >=97 && buffer[i] < 97+26){
                buffer[i] -= 32;
            }
            else if(buffer[i] >= 65 && buffer[i] < 65+26){
                buffer[i] += 32;            //capital to small letter
            }
        }
        fout<<buffer;
    }
    
    
    
    
    return 0;
}

