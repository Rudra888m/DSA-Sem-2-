#include<stdio.h>

int main() {
    int arr[100], freq[100];
    int i, j, n, count;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter %d element : ", i+1);
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for(i=0; i<n; i++) {
        if(freq[i] != 0) {
            count = 1;
            for(j=i+1; j<n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;
                }
            }
            freq[i] = count;
        }
    }

    printf("\nElement Frequency : \n");
    for(i=0; i<n; i++) {
        if(freq[i] != 0) {
            printf("%d --> %d, ", arr[i], freq[i]);
        }
    }

    printf("\nUnique Elements : \n");
    for(i=0; i<n; i++) {
        if(freq[i] == 1) {
            printf("%d\t", arr[i]);
        }
    }

    return 0;
}