#include <stdio.h>

int main(){
    int n1, n2;
    printf("Please Enter number a: ");
    scanf("%d", &n1);
    printf("Please Enter number b: ");
    scanf("%d", &n2);
    printf("a + b = %d\n", n1+n2);
    printf("a - b = %d\n", n1-n2);
    printf("a & b = %d\n", n1&n2);
    printf("a | b = %d\n", n1|n2);
    printf("a ^ b = %d\n", n1^n2);
    return 0;
}