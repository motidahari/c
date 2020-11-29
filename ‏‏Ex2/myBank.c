#include <stdio.h>  
#include <math.h>
/**
 * created by yochai modechai dahari
 * ID: 308212570
*/

double bank[50];
int OpenAccounts[50];
int openedBank = 0;
int size = 0;


void toString2(){
        for(int i = 0; i < 50; i++){
            printf("bank[%d] = %f \n",i, bank[i] );
            printf("OpenAccounts[%d] = %d\n",i, OpenAccounts[i] );
        }
        printf("\n");
}

void toString(){
        for(int i = 0; i < 50; i++){
            if(OpenAccounts[i] == 1){
                printf("The balance of account number %d is: %.2f \n\n",i + 901, bank[i] );
            }
        }
        printf("\n");
}
int openAccount(double amount){
    if(size < 50){
        if( amount > 0){
            for(int i = 0; i < sizeof(OpenAccounts); i++){
                if(OpenAccounts[i] == 0){
                    float rounded = ((int)(amount * 100 + .5) / 100.0);
                    bank[i] = (double)rounded;
                    OpenAccounts[i] = 1;
                    printf("New account number is: %d \n", 901 + i );
                    size++;
                    return 901 + i ; 
                }
            }
        }
    }
    printf("Failed to create account \n");
    return -1;
}
int openAccount2(double amount){
    if(openedBank < 50 && openedBank >= 0 && amount > 0 && OpenAccounts[openedBank] == 0){
        bank[openedBank] = amount;
        OpenAccounts[openedBank] = 1;
        printf("The new account is: %d \n", 901 + openedBank + 1);
        openedBank += 1;
        return 901 + openedBank  ;
    }
    printf("Failed to create account %d \n", 901 + openedBank);
    return -1;
}
int getBalance(int account_number){
    account_number = account_number - 901;
    if(account_number >= 0 && account_number < 50 && OpenAccounts[account_number] == 1){
        printf("The balance of account number 901 is: %.2f \n", bank[account_number]);
        return bank[account_number];
    }
    printf("The account %d does not exist  \n\n", account_number + 901);
    return -1;
}

double updateBalance(int account_number, double money){
    account_number = account_number - 901;
    if(account_number >= 0 && account_number < 50 && OpenAccounts[account_number] == 1 && money > 0){
        float rounded = ((int)(money * 100 + .5) / 100.0);
        bank[account_number] += (double)rounded;
        printf("The new balance is: %.2f \n", bank[account_number]);
        return bank[account_number];
    }
    printf("The account %d does not exist  \n\n", account_number + 901);
    return -1;
}

double pullMoney(int account_number, double money){
    account_number = account_number - 901;
    if(account_number >= 0 && account_number < 50 && OpenAccounts[account_number] == 1 && money <= bank[account_number] && money >= 0){
            bank[account_number] -= money;
            printf("The new balance is: %.2f \n\n", bank[account_number]);
            return bank[account_number];
    }
    printf("The account does not exist or the amount you entered is less than 0 or you do not have enough money in the account \n");
    return -1;
}


int close(int account_number){
    account_number = account_number - 901;
    if(account_number >= 0 && account_number < 50 && OpenAccounts[account_number] == 1){
        bank[account_number] = 0;
        OpenAccounts[account_number] = 0;
        printf("Closing account %d was successfully \n", account_number + 901);
        return account_number;
        size--;
    }
    printf("Account %d failed to close \n", account_number + 901);
    return -1;
}
int addRate(double interest_rate){
    if(interest_rate > 0){
        for(int i = 0; i < sizeof(bank); i++){
            if(OpenAccounts[i] == 1){
                bank[i] = ((interest_rate /100) * bank[i]) + bank[i];
                printf("add Rate successfully and the new balance to: %.2f \n", bank[i]);
            }
        }
        return 1;
    }
    printf("failed to update the rate \n");
    return -1;
}


int closeAllAccount(){
    for(int i = 0; i < 50; i++){
        bank[i] = 0;
        OpenAccounts[i] = 0;
        size = 0;
       //close(i);
    }
    return 0;
}
int getMoney(int i, double money){
    if(i > 900 && i < 951){
    int z = i - 900;
        if(money >= 0 ){
            bank[z] = money;
            return i;
        }
    }
    return -1;
}