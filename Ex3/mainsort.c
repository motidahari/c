#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   
#include "isort.h"

#define SIZE 50

int arr[SIZE];

int main () {
    int number,i;
    for (i = 0; i < SIZE; i++) {
        printf("Enter a number:");
        scanf("%d",&number);
     if(number < 0){
         i--;
     }else{
        *(arr+i)=number;
     }
   }
    insertion_sort(&arr[0],sizeof(arr)/4);
    toString(&arr[0],sizeof(arr)/4);
    return 0;
}

