/* 
 * File:   binarystrng.cpp
 * Author: Valentinno Cruz
 * Created on June 23, 2020, 11:42 PM
 * Purpose: Binary string
 */

//System Libraries Here
#include <stdio.h>
#include <string.h>
using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here

//Binary search function for array of sorted String
  int binarySearch(char Str[50][20], char Search[20] ,int length) {
  int left = 0 ;
  int right = length - 1;
  int mid,result;

    while (left <= right)
    {
    mid = left + (right - left) / 2;
   
        if (strcmp(Search,Str[mid]) == 0)
           result = 0;   
  
    // Check if String is present at mid
    if (result == 0)
        return mid;
  
    // If String greater, ignore left half
    if (strcmp(Search,Str[mid]) > 0)
        left = mid + 1;   
    // If String is smaller, ignore right half
    else
        right = mid - 1;
    }
  
    return -1;
    }
  
//Program Execution Begins Here  
int main(int argc, char** argv) {
    
    
    //Declare all Variables Here
    
    char strings[50][20],searchString[20];
    int index,length,result;
  
    
    //Input or initialize values Here
   
    
    
    //Process/Calculations Here
    printf("Enter No. of strings u want: ");
    scanf("%d",&length);
  
    printf("Enter All String but in sorted order.....\n");
    for(index=0; index<length; index++)
    {
        printf("S[%d] ? ",index);
      
        getchar(); //read characters and ingores (NULL)
        //read string with spaces
        scanf("%[^\n]s",strings[index]);
    }
  
    printf("\n Array of Strings You Enter...\n");
    for(index=0; index<length; index++)
    {
        printf("[%d]: %s\n",index,strings[index]);
    }

    printf("\nEnter string For search: ");
        getchar();
    scanf("%[^\n]s",searchString);
  
    result = binarySearch(strings, searchString, length);
  
    if (result == -1)
         rintf("\nString not present");
    else
        printf("\nString found at index %d",result);
    
    
    //Output Located Here
   
    
    //Exit
    return 0;
}

