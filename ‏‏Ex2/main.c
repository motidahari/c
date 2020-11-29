#include <stdio.h>  
#include <math.h>
#include "myBank.h"
#include "myBank.c"
/**
 * created by yochai modechai dahari
 * ID: 308212570
*/
void print(){
    printf("Please choose a transaction type:\n");
    printf("O-Open Account\n");
    printf("B-Balance Inquiry\n");
    printf("D-Deposit\n");
    printf("W-Withdrawal\n");
    printf("C-Close Account\n");
    printf("I-Interest\n");
    printf("P-Print\n");
    printf("E-Exit:\n\n");
}

char program(char z) {

    if(z == 'O'){
        double amount;
        printf("Please enter amount for deposit: \n");
        scanf(" %lf", &amount);
        openAccount(amount);
    }else if(z == 'B'){
        int account_number;
        printf("Please enter account number: \n");
        scanf(" %d", &account_number);
        getBalance(account_number);
    }else if(z == 'D'){
        int account_number;
        printf("Please enter account number: \n");
        scanf(" %d", &account_number);
        double money;
        printf("Please enter the amount to deposit: \n");
        scanf(" %lf", &money);
        updateBalance(account_number,money);
    }else if(z == 'W'){
        int account_number;
        printf("Please enter account number: \n");
        scanf(" %d", &account_number);
        double money;
        printf("Please enter the amount to withdraw: \n");
        scanf(" %lf", &money);
        pullMoney(account_number,money);
    }else if(z == 'C'){
        int account_number;
        printf("Insert account number \n");
        scanf(" %d", &account_number);
        close(account_number);
    }else if(z == 'I'){
        double interest_rate;
        printf("Please enter interest rate: \n");
        scanf(" %lf", &interest_rate);
        addRate(interest_rate);
    }else if(z == 'P'){
        toString();
    }else if(z == 'E'){
        closeAllAccount();
        return 'E';
    }
    print();
    while (getchar() != '\n');
    return '1'; 
}

// char getInput(){
//     char z;
//     scanf("%c", &z);
    //  while (getchar() != '\n');
//     return z;
    
// }
int main(){
    char z;
    print();
    while(z != 'E'){ 
        scanf("%s", &z);
        while (getchar() != '\n');
        z = program(z);
    }
    //while (program() != 'Z'){}
    return 0;
}


