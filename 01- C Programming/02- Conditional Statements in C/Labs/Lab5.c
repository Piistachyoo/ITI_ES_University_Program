#include <stdio.h>

int main(){
    int ID;

    /* Input data */
    printf("Please Enter Your ID: ");
    scanf("%d", &ID);

    /* Process data */
    switch(ID){
        case 1234: 
            printf("Welcome Ahmed\n");
            break;
        case 5678:
            printf("Welcome Youssef\n");
            break;
        case 1145:
            printf("Welcome Mina\n");
            break;
        default:
            printf("Wrong ID\n");
            break;
    }

    return 0;
}