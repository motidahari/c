#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   


void shift_element(int *arr, int i) {
    int j;
    for(j = 0; j < i; j++){
        *(arr+i+1-j) = *(arr+i-j);
    }
    *(arr+1) = 0;
}
void insertion_sort(int* arr , int len){
    int temp,i,count,*point = NULL;
    for(i = 1; i < len; i++ ){
        point = (arr+i-1);
        count = 0;
        while(point > (arr-1)){
            if(*(arr+i) < *point){
                count++;
            }
            point--;
        }
        temp = *(arr + i);
        shift_element((arr+i-count-1),count);
        *(arr+i-count) = temp;
    }

}
void printArr(int var[],int run){
    int j;
    for(j = 0 ; j < run ; j++){
        printf("var[%d] = %d\n",j,var[j]);
    }
    printf("\n\n");
}
void toString(int var[],int run){
    int j;
    for(j = 0 ; j < run ; j++){
        if(j == 0){
            printf("%d",*(var + j));
        }else{
            printf(",%d",*(var + j));
        }
    }
    printf("\n");
}