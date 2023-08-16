#include <stdio.h>

int main(){
    int rating;

    /* Input data */
    printf("Please enter rating: ");
    scanf("%d", &rating);

    /* Process data */
    if((0 <= rating) && (rating < 50))
        printf("Your rating is Failed");
    else if((50 <= rating) && (rating < 65))
        printf("Your rating is Normal");
    else if((65 <= rating) && (rating < 75))
        printf("Your rating is Good");
    else if((75 <= rating) && (rating < 85))
        printf("Your rating is Very Good");
    else if(85 <= rating)
        printf("Your rating is Excellent");
    else
        printf("You entered wrong rating!");

    return 0;
}