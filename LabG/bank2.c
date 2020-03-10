#include <stdio.h>
#include <stdlib.h>

struct BANK_ACCOUNT {
    char type; //  'S' = savings, 'C' = checking
    double balance;
    union ACCOUNT_SPECIFIC {
        double charge; // for withdrawal from savings accounts
        int credit_score; // for checking account
    } specific;
};

int main(){
    struct BANK_ACCOUNT *accounts;
    accounts = (struct BANK_ACCOUNT*) calloc(100,sizeof(struct BANK_ACCOUNT));
    int nextSpot = 0;
    int newAccounts = 0; 

    printf("Enter number of new accounts : ");
    scanf("%d", &newAccounts);

    for(int i = 0 ; i < newAccounts ; i++){
        printf("Enter account type: ");
        //Note the space before %c
        scanf(" %c", &(accounts+nextSpot)->type);
        printf("Enter account balance: ");
        scanf("%lf", &(accounts+nextSpot)->balance);

        if((accounts+nextSpot)->type=='S'){
            printf("Enter charge: ");
            scanf("%lf", &(accounts+nextSpot)->specific.charge);
        }else{
            printf("Enter credit score: ");
            scanf("%d", &(accounts+nextSpot)->specific.credit_score);
        }
        printf("******* Account Created **********\n");
        nextSpot++;
    }
    
    printf("******* Accounts Record **********\n");
    for(int i = 0 ; i < nextSpot; i++){
        if((accounts+i)->type =='S'){
            printf("Account number : %d : type: %c, balance: %f, charge: %f\n", i+1 ,(accounts+i)->type, (accounts+i)->balance, (accounts+i)->specific.charge);
        }else{
            printf("Account number : %d : type: %c, balance: %f, credit_Score: %d\n", i+1 ,(accounts+i)->type, (accounts+i)->balance, (accounts+i)->specific.credit_score);
        }
    }

    return 0;
}
