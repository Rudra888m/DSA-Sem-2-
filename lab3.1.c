#include<stdio.h>

int main() {
    //Arrays of pointers...
    int a = 100, b = 200, c = 300;
    int *arr[3];

    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("\n\n");
    printf("Arrays of pointers : \n");
    for(int i=0; i<3; i++) {
        printf("Value at arr[%d] : %d\n", i+1, *arr[i]);
    }
    printf("\n\n");

    //Pointers to arrays...
    int arr1[3] = {100, 200, 300};
    int (*ptr)[3];

    ptr = &arr1;

    printf("Pointers to arrays : \n");
    for(int i=0; i<3; i++) {
        printf("Value at arr[%d] : %d\n", i+1, (*ptr)[i]);
    }

    return 0;
}