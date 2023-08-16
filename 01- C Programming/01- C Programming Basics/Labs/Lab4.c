#include <stdio.h>

int main(){
    int x = 7;
    int y = 4;
    printf("x = %d\ny = %d\n", x, y);
    printf("z = %d\n", x & y);
    printf("k = %d\n", x | y);
    printf("m = %d\n", x ^ y);
    printf("L = %d\n", x >> 1);
    printf("N = %d\n", x << 2);
    return 0;
}