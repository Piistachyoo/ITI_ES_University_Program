#include <stdio.h>

int main(){
    int number;
    printf("Please enter number: ");
    scanf("%d", &number);
    if(number & 1 == 1)
        printf("Number is odd!\n");
    else
        printf("Number is even!\n");
    return 0;
}