#include<stdio.h>

int main() {
    int arr[100];
    int i, n;

    printf("Enter number of elements (Maximum 100) : ");
    scanf("%d", &n);

    if(n<=0) {
        printf("Invalid number of elements.");
        return 0;
    }

    for(i=0; i<n; i++) {
        printf("Enter %d number : ", i+1);
        scanf("%d", &arr[i]);
    }

    int min, max;
    min = arr[0];
    max = arr[0];

    for(i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    printf("Maximum element is %d and minimum element is %d.", max, min);

    return 0;
}