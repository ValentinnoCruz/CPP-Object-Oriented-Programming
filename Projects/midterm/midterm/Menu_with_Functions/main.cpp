/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on June 17th, 2020, 10:20 AM
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <string.h>
#include <cstddef>
using namespace std;



struct Q1{
    char * name;
    char * address;
    int no;
    int begBalance;
    int * checks;
    int * deposits;
    int newBal;
};

struct Q2{
    int hours;
    float rate;
    char * name;
    float pay;
};

int fac(int n){
    if(n == 0 || n == 1)
        return 1;
    return n* fac(n-1);
}

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int num){

    Primes *primes = new Primes;
    primes->nPrimes = 0;

    int p = 2;
    int n = num;
    while(n != 1){
        if(n%p == 0){
            primes->nPrimes++;
            while(n%p == 0)
                n /= p;
        }
        p++;
    }
    primes->prime = new Prime[primes->nPrimes];
    n = num;
    p = 2;
    int x= 0;
    while(n != 1){
        if(n%p == 0){
            primes->prime[x].power = 0;
            primes->prime[x].prime = p;
            while(n%p == 0){
                primes->prime[x].power++;
                n /= p;
            }
            x++;
        }
        p++;
    }
    cout << (int)primes->nPrimes << endl;
    return primes;
}
void prntPrm(Primes *primes){
    if(primes->nPrimes != 0){
        cout << primes->prime[0].prime << "^" << (int) primes->prime[0].power;
    }
    for(int i = 1; i < primes->nPrimes; i++){
        cout << " * " << primes->prime[i].prime << "^" << (int) primes->prime[i].power;
    }
    cout << endl;
}

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='4');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    char buffer[80];
    Q1 * object = new Q1;
    cout<<"Problem 1"<<endl;
    cout<<"Enter name:\t";
    cin>>buffer;
    object->name = new char[strlen(buffer)+1];
    strcpy(object->name, buffer);
    cout<<"Enter address:\t";
    cin>>buffer;
    object->address = new char[strlen(buffer)+1];
    strcpy(object->address, buffer);
    cout<<"Enter account no:\t";
    cin>>object->no;
    cout<<"Enter beginning balance:\t";
    cin>>object->begBalance;
    cout<<"Enter all deposits this month. Press -1 when you're done.\n";
    int deposit = 0;
    int i = 0;
    object->deposits = new int[10];
    while(deposit != -1){
        object->deposits[i++] = deposit;
        cin>>deposit;
    }
    object->deposits[i] = -1;
    
    cout<<"Enter all cheques withdrawn this month. Press -1 when you're done.\n";
    int check = 0;
    i = 0;
    object->checks = new int[10];
    while(check != -1){
        object->checks[i++] = check;
        cin>>check;
    }
    object->checks[i] = -1;
    
    
    object->newBal = object->begBalance;
    for(int j = 0;object->deposits[j]!= -1; j++){
        object->newBal += object->deposits[j]; 
    }
    for(int j = 0;object->checks[j]!= -1; j++){
        object->newBal -= object->checks[j]; 
    }
    if(object->newBal < 0){
        cout<<"As the balance is overdrawn so a fees of 30$ is accessed.\n";
        object->newBal -= 30;
    }
    cout<<"New Balance:\t"<<object->newBal;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    Q2 ** objects = new Q2*[100];
    int index = 0;
    int hours;
    float rate;
    char buffer[80];
    
    cout<<"Problem 2"<<endl;
    int flag = 1;
    
    while(true){
        objects[index] = new Q2;
        cout<<"Enter employee name:\t";
        cin>>buffer;
        objects[index]->name = new char[strlen(buffer)+1];
        strcpy(objects[index]->name, buffer);
        cout<<"Enter hours worked:\t";
        cin>>hours;
        if(hours<=0){
            objects[index] = nullptr;
            break;
        }
        objects[index]->hours = hours;
        cout<<"Enter the rate:\t";
        cin>>rate;
        if(rate<=0){
            objects[index] = nullptr;
            break;
        }
        objects[index]->rate = rate;
        index++;
    }
    
    for(int i = 0;i<index;i++){
        //Calculating pay
        if(objects[i]->hours<=40){
            objects[i]->pay = objects[i]->hours * objects[i]->rate;
        }
        else if(objects[i]->hours > 40){
            objects[i]->pay = objects[i]->rate*40;
            objects[i]->hours -= 40;
            if(objects[i]->hours <=10){
                objects[i]->pay += objects[i]->hours * (objects[i]->rate * 1.5);
            }
            else{
                objects[i]->pay += objects[i]->rate*10*1.5;
                objects[i]->hours -= 10;
                objects[i]->pay += objects[i]->hours * (objects[i]->rate * 2);
            }
        }
        cout<<"Name:\t"<<objects[i]->name<<endl;
        cout<<"Amount:\t"<<objects[i]->pay<<endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    int num, flag = 0;
    cout<<"problem 4"<<endl;
    cout<<"Enter the number you want to encrpyt:\t";
    cin>>num;
    
    int temp = num;
    int first, second, third, fourth;
    fourth = num%10;
    num = num/10;
    third = num%10;
    num = num/10;
    second = num%10;
    num = num/10;
    first = num%10;
    if(first >7 || second > 7 || third > 7 || fourth > 7){
        cout<<"Wrong Digits Error!"<<endl;
        flag = 1;
    }
    if(flag != 1){
        first += 5;
        second += 5;
        third += 5;
        fourth += 5;

        first %= 8;
        second %= 8;
        third %= 8;
        fourth %= 8;

        swap(first, third);
        swap(second, fourth);
        
        int newNum = 0;
        newNum += first;
        newNum *= 10;
        newNum += second;
        newNum *= 10;
        newNum += third;
        newNum *= 10;
        newNum += fourth;
        cout<<"Encrypted Number:\t"<<first<<second<<third<<fourth<<endl;
        cout<<"Decrypted Number:\t"<<temp;
    }
    
    
    
    
    
    
}


void prblm5(){
    cout<<"Problem 5.\n";
    cout<<"For Byte Datatype:\n";
    cout<<"For unsigned  it can store upto 2^8 as a byte can store 8 bits and each bit can hold 2 values.\n";
    cout<<"For signed it can store from -2^4 to 2^4.\n";
    cout<<"For int Datatype:\n";
    cout<<"For unsigned it can store upto 2^32 as a int can store 32 bits and each bit can hold 2 values.\n";
    cout<<"For signed it can store from -2^16 to 2^16.\n";
    cout<<"For float Datatype:\n";
    cout<<"For unsigned it can store upto 2^32 as a float can store 32 bits and each bit can hold 2 values.\n";
    cout<<"For signed it can store from -2^16 to 2^16.\n";
    cout<<"For double Datatype:\n";
    cout<<"For unsigned it can store upto 2^64 as a double can store 64 bits and each bit can hold 2 values.\n";
    cout<<"For signed it can store from -2^32 to 2^32.\n";
    
}

void prblm6(){
    
}

void prblm7(){
    int n;
    cout<<"problem 7.\n";
    cout<<"Enter the number:\t";
    cin>>n;
    prntPrm(factor(n));
}