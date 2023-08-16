#include <stdio.h>

int main(){
    int hour_rate = 50;
    int working_hours, result;

    /* Get input */
    printf("Please Enter Your working hours: ");
    scanf("%d", &working_hours);

    /* Process data */
    result = working_hours * hour_rate;
    if(40 > working_hours)
        result *= 0.9;
 
    /* Output Data */
    printf("Your salary is %d\n\n", result);

    return 0;
}