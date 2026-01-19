#include<stdio.h>

int main() {
    int arr[100];
    int i, n, choice, value, index;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter %d element : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nOperations...\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("Choose opertaion (1/2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter element to insert : ");
        scanf("%d", &value);

        printf("Enter index to insert at (0 to %d) : ", n-1);
        scanf("%d", &index);

        if(index<0 || index>n-1) {
            printf("Invalid index!");
            return 0;
        }

        for(i=n-1; i>=index; i--) {
            arr[i+1] = arr[i];
        }

        arr[index] = value;
        n++;

        printf("Array after insertiation : ");
        for(i=0; i<n; i++) {
            printf("%d\t", arr[i]);
        }
    }

    else if(choice == 2) {
        printf("Enter index to delete from (0 to %d)", n-1);
        scanf("%d", &index);

        if(index<0 || index>n-1) {
            printf("Invalid index!");
            return 0;
        }

        for(i=index; i<n; i++) {
            arr[i] = arr[i+1];
        }
        
        n--;

        printf("Array after deletion : ");
        for(i=0; i<n; i++) {
            printf("%d\t", arr[i]);
        }
    }

    else {
        printf("Invalid choice!");
    }

    return 0;
}