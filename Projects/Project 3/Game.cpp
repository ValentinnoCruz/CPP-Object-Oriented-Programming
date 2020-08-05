/* 
 * File:   Game.cpp
 * Author: Cruz, Valentinno 
 * Created on August 05, 2021, 11:27 AM
 */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Game.h"
#include "Table.h"
#include "AI.h"

//overload ostream operator <<
ostream &operator << (ostream &strm, const Game &obj){
  strm<<"    REAL   "<<setw(obj.num*4+4)<<"FAKE\n";
    for(int i=0;i<obj.num;i++){
        strm<<setw(4)<<i;
    }
    strm<<"       ";
    for(int i=0;i<obj.num;i++){
        strm<<setw(4)<<i;
    }
    strm<<endl;
    //third line
    strm<<"  ";
    for(int i=0;i<obj.num;i++){
        strm<<"____";
    }
    strm<<"      ";
    for(int i=0;i<obj.num;i++){
        strm<<"____";
    }
    strm<<endl;
    //forth to num line
    for(int i=0;i<obj.num;i++){
        char row=i+65;
        strm<<row<<"| ";
        for(int j=0;j<obj.num;j++){
            strm<<obj.t->real[i][j];
            strm<<" "<<"| ";
        }
        strm<<"   "<<row<<"| ";
        
        for(int k=0;k<obj.num;k++){
            strm<<obj.t->fake[i][k];
            strm<<" "<<"| ";
        }
        strm<<endl;
        strm<<"  ";
        for(int l=0;l<obj.num;l++){
           strm<<"----";
        }
        strm<<"      ";
        for(int m=0;m<obj.num;m++){
           strm<<"----";
        }
        strm<<endl;
    }
}
Game::Game(int num):Table(num) {
  fstream io;
  char temp;
  io.open("unit.txt", ios::in | ios::binary);
  if(io.is_open()){
    for(int i=0;i<5;i++){
      io.read((&temp), sizeof(temp));
      unit[i]=temp-48;
    }
    io.close();
  }
  hit=0;
  miss=0;
  win=false;
}
//AI Game Constructor with placed ship
Game::Game(int num, char c):Table(num), AI(){
  cout<<"ai c\n";
  fstream io;
  char temp;
  io.open("unit.txt", ios::in | ios::binary);
  if(io.is_open()){
    for(int i=0;i<5;i++){
      io.read((&temp), sizeof(temp));
      unit[i]=temp-48;
    }
    io.close();
  }
  //ai place ship
  srand(static_cast<unsigned int>(time(0)));
  int count, pos;
  bool valid;
  for(int q=0;q<5;q++){
    do{
      valid=true;
      count=0;
      //random coordinates
      y1=rand()%(num-unit[q]);     //won't over size
      x1=rand()%(num-unit[q]);
      pos=rand()%2;
      if(pos==0){                 //0 horizontal
        for(int k=y1;k<y1+unit[q];k++){
            if(*(*(t->real+k)+x1)==' '){
                count++;
            }
        }
        if(count!=unit[q]){
            valid=false;
        }
        if(valid==true){
            for(int k=y1;k<y1+unit[q];k++){
                *(*(t->real+k)+x1)=unit[q]+48;
            }
        }
      }
      else{                      //1 vertical
        for(int k=x1;k<x1+unit[q];k++){
            if(t->real[y1][k]==' '){
                count++;
            }
        }
        if(count!=unit[q]){
            valid=false;
        }
        if(valid==true){
            for(int k=x1;k<x1+unit[q];k++){
                t->real[y1][k]=unit[q]+48;
            }
        }
      }
    }while(valid==false);
  }
//  hit=0;
//  miss=0;
}
void Game::print(Game &o) const{
  cout<<"   PLAYER 1"<<setw(num*4+4)<<"A.I.\n";
    for(int i=0;i<num;i++){
        cout<<setw(4)<<i;
    }
    cout<<"       ";
    for(int i=0;i<num;i++){
        cout<<setw(4)<<i;
    }
    cout<<endl;
    //third line
    cout<<"  ";
    for(int i=0;i<num;i++){
        cout<<"____";
    }
    cout<<"      ";
    for(int i=0;i<num;i++){
        cout<<"____";
    }
    cout<<endl;
    //forth to num line
    for(int i=0;i<num;i++){
        char row=i+65;
        cout<<row<<"| ";
        for(int j=0;j<num;j++){
            cout<<t->real[i][j];
            cout<<" "<<"| ";
        }
        cout<<"   "<<row<<"| ";
        
        for(int k=0;k<num;k++){
            cout<<o.t->real[i][k];
            cout<<" "<<"| ";
        }
        cout<<endl;
        cout<<"  ";
        for(int l=0;l<num;l++){
           cout<<"----";
        }
        cout<<"      ";
        for(int m=0;m<num;m++){
           cout<<"----";
        }
        cout<<endl;
    }
}
void Game::Place(Game &o){
  //print table
  print(o);
  //place ship
  for(int q=0;q<5;q++){
    do{
      do{
        do{
          valid=true;   //reset
          cout<<"Choose the coordinates to place the ";
          cout<<unit[q]<<"-unit ship with A1A5 form : ";
          cin>>place;
          try{
            placeCheck();
          }
          catch(string temp){//place ship exception
            valid=false;
            cout<<temp;
          }
        }while(valid==false);
        cout<<place[0]-65<<place[1]-48<<place[2]-65<<place[3]-48<<endl;
        y1=place[0]-65;
        y2=place[2]-65;
        x1=place[1]-48;
        x2=place[3]-48;
        cout<<y1<<x1<<y2<<x2<<endl;
        try{
          tableCheck(q);
        }
        catch(string temp){
          cout<<temp;
        }
      }while(valid==false);
    }while(valid==false);
    cout<<"\n\n\n\n\n\n\n\n\n";
    //table
    print(o);
  }
}
void Game::placeCheck(){
  string temp;
  if(place.size()!=4){
    temp="ERROR: String size\n";
    throw temp;
  }
  else if(place[0]<'A' || place[0]>'J' || 
          place[2]<'A' || place[2]>'J' ||
          isdigit(place[1]==0 || isdigit(place[3])==0)){
    temp="ERROR: Invalid format\n";
    throw temp;
   }
}
void Game::tableCheck(int q){
  int max,min;
  int count=0;
  string temp;
  if(y1==y2){     //x is same
    if(abs(x1-x2)!=unit[q]-1){   //check unit invalid
      valid=false;
      temp="ERROR: Not match units\n";
      throw temp;
    }
    else{                   //valid
      if(x1>x2){          //check which larger
        max=x1;
        min=x2;
      }
      else{
        max=x2;
        min=x1;
      }
//      cout<<"max="<<max<<endl;
//      cout<<"min="<<min<<endl;
//      cout<<"p"<<y1<<endl;
      for(int k=min;k<=max;k++){         //check overlap
        if(t->real[y1][k]==' '){
          count++;
        }
      }
      if(count!=unit[q]){
        valid=false;
        temp="ERROR: overlap\n";
        throw temp;
      }
      if(valid==true){
        for(int k=min;k<=max;k++){
          *(*(t->real+y1)+k)=unit[q]+48;
        }
      }
    }
  }
        if(x1==x2){           //y is same
          if(abs(y1-y2)!=unit[q]-1){   //check unit
            valid=false;
            temp="ERROR: not match unit\n";
            throw temp;
          }
          else{                 //valid
            if(y1>y2){
              max=y1;
              min=y2;
            }
            else{
              max=y2;
              min=y1;
            }
//            cout<<"max="<<max<<endl;
//            cout<<"min="<<min<<endl;
//            cout<<"p"<<y1<<endl;
            for(int k=min;k<=max;k++){
              if(*(*(t->real+k)+x1)==' '){
                count++;
              }
            }
            if(count!=unit[q]){
              valid=false;
              temp="ERROR: overlap\n";
              throw temp;
            }
            if(valid==true){
              for(int k=min;k<=max;k++){
                *(*(t->real+k)+x1)=unit[q]+48;
              }
            }
          }
        }
        if(x1!=x2 && y1!=y2){
          valid=false;
          temp="ERROR: not horizontal or vertical\n";
          throw temp;
        }
}
void Game::start(Game &o){
  fstream io;
  do{
//    win=false;
    //player fire
    fire(o);
    if(over==true){
      win=true;
      cout<<"You win!\n";
      io.open("result.txt", ios::out | ios::binary);
      char text[]={'R', 'e', 's', 'u', 'l', 't', ' ', 'w', 'i', 'n', '\n'};
      io.write(text, sizeof(text));
    }
    if(win==false){
      cout<<"AI fire ";
      //ai fire
      fire(o, 0);
      if(over==true){
        win=false;
        cout<<"You lose...\n";
        io.open("result.txt", ios::out | ios::binary);
        char text[]={'R', 'e', 's', 'u', 'l', 't', ' ', 'l', 'o', 's', 'e', '\n'};
        io.write(text, sizeof(text));
      }
    }
  }while(over==false);
  cout<<"Result outputs to result.txt\n";
}
void Game::fire(Game &o){
  string fire;
  do{
    valid=true;
    cout<<"Your turn, enter a coordinate to fire in A0 form :";
    cin>>fire;
    if(fire.length()!=2){
      valid=false;
      cout<<"size\n";
    }
    //fire[1]<'0' || fire[1]]>'9'
    else if(fire[0]<'A' || fire[0]>'J' ||fire[1]<'0' || fire[1]>num+48-1){
      valid=false;
      cout<<"x/y\n";
    }
    else if(o.t->real[y1][x1]=='O' && o.t->real[y1][x1]=='X'){
      valid=false;
      cout<<"Overlap\n";
    }
  }while(valid==false);
  y1=fire[0]-65;
  x1=fire[1]-48;
  //hit
  if(o.t->real[y1][x1]>='2' && o.t->real[y1][x1]<='5'){
    cout<<"Hit!\n";
    o.t->real[y1][x1]='X';
    o.t->fake[y1][x1]='X';
    hit++;
  }
  else{
    cout<<"Miss...\n";
    o.t->real[y1][x1]='O';
    o.t->fake[y1][x1]='O';
    miss++;
  }
  //print table
  print(o);
  //check ai table
  check(o);
}
void Game::fire(Game &o, int dum){
  srand(static_cast<unsigned int>(time(0)));
  for(int i=0;i<3;i++){
    o.delay();
  }
  int hplan;
  o.done=false;
  for(int i=0;i<4;i++){
    o.cross[i]=true;
  }
  do{
//    cout<<o.crossdone<<" "<<o.finish<<" "<<o.goback<<" "<<o.done<<" "<<o.oppcombo<<" "<<o.combo<<endl;
//    cin>>hplan;
//    cout<<"o.done = false\n";
    o.done=false;
    if(o.crossdone==true && o.finish==true && 
       o.goback==true && o.done==false && 
       o.oppcombo==0 && o.combo==0){
      //randon fire
      cout<<"random fire\n";
      o.goback=true;
      do{
        cout<<"inner loop(random fire)\n";
        valid=true;
//        cout<<num<<endl;
        o.x=rand()%num;
//        cout<<"first rand\n";
        o.y=rand()%num;
//        cout<<"second rand\n";
//        cout<<o.y<<" "<<o.x<<endl;
        if(t->real[o.y][o.x]=='O' || t->real[o.y][o.x]=='X'){
          valid=false;
          cout<<"overlap\n";
        }
      }while(valid==false);
      o.cx=o.x+48;
      o.cy=o.y+65;
//      cout<<"ai fire";
      cout<<o.cy<<o.cx<<"\n";
      if(t->real[o.y][o.x]!=' '){
        t->real[o.y][o.x]='X';
        cout<<"Hit!\n";
        o.hx=o.x;
        o.hy=o.y;
        o.bhit=true;
        o.crossdone=false;
        o.finish=false;
        o.combo=false;
        o.done=true;
        o.oneend=false;
        o.hit++;
      }
      else{
        t->real[o.y][o.x]='O';
        cout<<"Miss...\n";
        o.done=true;
        o.miss++;
      }
    }
    //move after hit
    if(o.bhit==true && o.finish==false && 
       o.crossdone==false && o.combo==0 && 
       o.oppcombo==0 && o.done==false){
      do{
        cout<<"random cross\n";
        o.y=o.hy;
        o.x=o.hx;
        //check cross rand
        hplan=rand()%4;
        if(hplan==0) o.y=o.hy-1;
        if(hplan==1) o.y=o.hy+1;
        if(hplan==2) o.x=o.hx-1;
        if(hplan==3) o.x=o.hx+1;
        cout<<"hplan = "<<hplan<<endl;
        //check over size
        if(o.y<0 || o.y>num-1 || o.x<0 || o.x>num-1){
          cout<<"Out table\n";
          o.cross[hplan]=false;
        }
        else if(t->real[o.y][o.x]=='X' || t->real[o.y][o.x]=='O'){
          cout<<"overlap\n";
          o.cross[hplan]=false;
        }
        if(o.cross[0]==o.cross[1] && o.cross[1]==o.cross[2] && 
           o.cross[2]==o.cross[3] && o.cross[0]==false){
          cout<<"test all 4 but invalid\n";
          o.crossdone=true;
          o.finish=true;
          o.goback=true;
        }
      }while(o.crossdone==false && o.cross[hplan]==false);
      //valid
      if(o.crossdone==false){
        cout<<"check hit or miss by cross rand xy\n";
        o.cx=o.x+48;
        o.cy=o.y+65;
        cout<<"ai fire ";
        cout<<o.cy<<o.cx<<"\n";
        if(t->real[o.y][o.x]!=' '){
          t->real[o.y][o.x]='X';
          cout<<"Hit!\n";
          o.done=true;
          o.combo++;
          o.crossdone=true;
          o.hit++;
        }
        else{
          t->real[o.y][o.x]='O';
          cout<<"Miss...\n";
          o.done=true;
          o.miss++;
        }
      }
      else{
        cout<<"crossdone=true, go back to rand\n";
        o.goback=true;
      }
    }
    else if(o.combo>0 && o.oneend==false && 
            o.done==false && o.crossdone==true){
      cout<<"Second hit\n";
      valid=true;
      if(o.hx==o.x){
        cout<<"same x\n";
        if(o.hy>o.y) o.y=o.hy-o.combo-1;
        else         o.y=o.hy+o.combo+1;
        if(o.y<0 || o.y >num-1){
            valid=false;
        }
        if(valid==true){
          if(t->real[o.y][o.x]=='X' || t->real[o.y][o.x]=='O'){
            valid=false;
          }
          if(t->real[o.y][o.x]=='O'){
            o.finish=true;
            o.goback=true;
            o.crossdone=true;
            o.combo=0;
            o.oppcombo++;
            o.oneend=true;
          }
          if(valid==true){
            o.cx=o.x+48;
            o.cy=o.y+65;
//            cout<<"ai fire ";
            cout<<o.cy<<o.cx<<"\n";
            if(t->real[o.y][o.x]!=' '){
              t->real[o.y][o.x]='X';
              cout<<"Hit!!!\n";
              o.done=true;
              o.combo++;
              o.hit++;
            }
            else{
              t->real[o.y][o.x]='O';
              cout<<"Miss...\n";
              o.done=true;
              o.oneend=true;
              o.oppcombo++;
              o.miss++;
            }
          }
        }
        else{ //check ->GO TO OPPCOMBO
          cout<<"next xy invalid change to opposite side\n";
          o.combo=0;
          o.oneend=true;
          o.crossdone=true;
          o.oppcombo++;
          o.combohit=false;
        }
      }
      if(o.hy==o.y){
        cout<<"same y\n";
        if(o.hx>o.x) o.x=o.hx-o.combo-1;
        else o.x=o.hx+o.combo+1;
        if(o.x<0 || o.x >num-1){
          valid=false;
          o.combo=0;
          o.goback=true;
          o.finish=true;
        }
        if(valid==true){
          if(t->real[o.y][o.x]=='X' || t->real[o.y][o.x]=='O'){
            valid=false;
            o.finish=true;
            o.goback=true;
          }
          if(valid==true){
            o.cx=o.x+48;
            o.cy=o.y+65;
//            cout<<"ai fire ";
            cout<<o.cy<<o.cx<<"\n";
            if(t->real[o.y][o.x]!=' '){
              t->real[o.y][o.x]=='X';
              o.combo++;
              o.done=true;
              o.hit++;
            }
            else{
              t->real[o.y][o.x]=='O';
              cout<<"Miss...\n";
              o.done=true;
              o.oneend=true;
              o.oppcombo++;
              o.combo=0;
              o.combohit=false;
              cout<<"oneend==true\n";
              cout<<"done==true\n";
              o.miss++;
            }
          }
        }
        if(valid==false){ //GO TO OPPCOMBO
          cout<<"next xy invalid change to other side\n";
          o.combo=0;
          o.oneend=true;
          o.crossdone=true;
          o.oppcombo++;
          o.combohit=false;
        }
      }
    }
    //check other side
    else if(o.oppcombo>0 && o.oneend==true && o.done==false){
      cout<<"one side end check other side\n";
      cout<<"oppcombo = "<<o.oppcombo<<endl;
      if(o.hx==o.x){
        cout<<"same x\n";
        if(o.combohit==false){
          if(o.hy>o.y) o.y=o.hy+o.oppcombo;
          else o.y=o.hy-o.oppcombo;
        }
        else{
          if(o.y>o.hy) o.y=o.hy+o.oppcombo;
          else o.y=o.hy-o.oppcombo;
        }
        cout<<o.y<<o.x<<endl;
        if(o.y<0 || o.y>num-1 || t->real[o.y][o.x]=='O' || 
           t->real[o.y][o.x]=='X'){
          o.oppcombo=0;
          o.goback=true;
          o.finish=true;
          o.crossdone=true;
          o.combo=0;
          o.done=false;
          cout<<"overlap or oversize\n";
        }
        else{
          o.cx=o.x+48;
          o.cy=o.y+65;
//          cout<<"ai fire ";
          cout<<o.cy<<o.cx<<"\n";
          if(t->real[o.y][o.x]!=' '){
            t->real[o.y][o.x]='X';
            cout<<"Hit!!!\n";
            o.done=true;
            o.oppcombo+=1;
            o.combohit=true;
            o.hit++;
          }
          else{
            t->real[o.y][o.x]='O';
            cout<<"Miss...\n";
            o.done=true;
            o.combo=0;
            o.oppcombo=0;
            o.finish=true;
            o.goback=true;
            o.crossdone=true;
            o.miss++;
          }
        }
      }
      else if(o.hy==o.y){
        cout<<"same y\n";
        if(o.combohit==false){
          if(o.hx>o.x) o.x=o.hx+o.oppcombo;
          else o.x=o.hx-o.oppcombo;
        }
        else{
          if(o.x>o.hx) o.x=o.hx+o.oppcombo;
          else o.x=o.hx-o.oppcombo;
        }
        cout<<o.y<<o.x<<endl;
        if(o.x<0 || o.x>num-1 || t->real[o.y][o.x]=='O' || 
           t->real[o.y][o.x]=='X'){
          o.oppcombo=0;
          o.goback=true;
          o.finish=true;
          o.crossdone=true;
          o.combo=0;
          o.done=false;
          cout<<"overlap or oversize\n";
        }
        else{
          o.cx=o.x+48;
          o.cy=o.y+65;
//          cout<<"ai fire ";
          cout<<o.cy<<o.cx<<"\n";
          if(t->real[o.y][o.x]!=' '){
            t->real[o.y][o.x]='X';
            cout<<"Hit!!!\n";
            o.done=true;
            o.oppcombo+=1;
            o.combohit=true;
            o.hit++;
          }
          else{
            t->real[o.y][o.x]='O';
            cout<<"Miss...\n";
            o.done=true;
            o.combo=0;
            o.oppcombo=0;
            o.finish=true;
            o.goback=true;
            o.crossdone=true;
            o.miss++;
          }
        }
      }
    }
  }while(o.done==false);
  //print table
  print(o);
  //check player table
  check();
}
//check player table
void Game::check(){
  over=true;
  for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
      if(t->real[i][j]>='2' && t->real[i][j]<='5')
        over=false;
    }
  }
}
//check ai table
void Game::check(Game &o){
  over=true;
  for(int i=0;i<num;i++){
    for(int j=0;j<num;j++){
      if(o.t->real[i][j]>='2' && o.t->real[i][j]<='5')
        over=false;
    }
  }
}
Game::~Game(){
//  for (int i=0;i<num;i++){
//         delete[] t->fake[i];
//         delete[] t->real[i];
//    }    
//    delete[] t->fake;
//    delete[] t->real;
//  delete t;
}