#include <stdio.h>

int main(){
    int x, y;
    x = 50 && 0; /* False condition */
    y = 0 || 50; /* True condition  */

    printf("False value in GCC = %d\n", x);
    printf("True value in GCC = %d\n\n", y);

    return 0;
}