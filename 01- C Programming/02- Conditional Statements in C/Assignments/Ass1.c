#include <stdio.h>

int main(){
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, input;

    /* Input data */
    printf("Enter Number 1: ");
    scanf("%d", &n1);
    printf("Enter Number 2: ");
    scanf("%d", &n2);
    printf("Enter Number 3: ");
    scanf("%d", &n3);
    printf("Enter Number 4: ");
    scanf("%d", &n4);
    printf("Enter Number 5: ");
    scanf("%d", &n5);
    printf("Enter Number 6: ");
    scanf("%d", &n6);
    printf("Enter Number 7: ");
    scanf("%d", &n7);
    printf("Enter Number 8: ");
    scanf("%d", &n8);
    printf("Enter Number 9: ");
    scanf("%d", &n9);
    printf("Enter Number 10: ");
    scanf("%d", &n10);
    printf("Enter the value to search: ");
    scanf("%d", &input);

    if(input == n1)
        printf("Value exists at element number 1");
    else if(input == n2)
        printf("Value exists at element number 2");
    else if(input == n3)
        printf("Value exists at element number 3");
    else if(input == n4)
        printf("Value exists at element number 4");
    else if(input == n5)
        printf("Value exists at element number 5");
    else if(input == n6)
        printf("Value exists at element number 6");
    else if(input == n7)
        printf("Value exists at element number 7");
    else if(input == n8)
        printf("Value exists at element number 8");
    else if(input == n9)
        printf("Value exists at element number 9");
    else if(input == n10)
        printf("Value exists at element number 10");
    else
        printf("Value doesn't exist!");
    return 0;
}