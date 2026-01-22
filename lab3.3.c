#include<stdio.h>

void swapfunction(int *x, int *y);

int main() {
    int a, b;

    printf("\nEnter a : ");
    scanf("%d", &a);

    printf("Enter b : ");
    scanf("%d", &b);

    printf("\nBefore swapping : a = %d, b = %d\n", a, b);
    swapfunction(&a, &b);
    printf("After swapping : a = %d, b = %d\n", a, b);
}

void swapfunction(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}