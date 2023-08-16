#include<stdio.h>

int main(){
    int i = 10;
    int *ptr = &i;
    printf("i before changes is: %d\n", i);
    *ptr = 20;
    printf("i after changes is: %d", i);
    return 0;
}