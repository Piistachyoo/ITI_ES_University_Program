#include <stdio.h>

int sum(int *x, int *y);

int main(){
    int n1, n2, result;
    printf("Enter n1: ");
    scanf("%d", &n1);
    printf("Enter n2: ");
    scanf("%d", &n2);
    result = sum(&n1, &n2);
    printf("result = %d", result);
    return 0;
}

int sum(int *x, int *y){
    return *x + *y;
}
