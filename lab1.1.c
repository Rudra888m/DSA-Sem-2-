#include<stdio.h>

int main() {
    char arr[100];
    int i, n;

    printf("Enter number of characters : ");
    scanf("%d", &n);
    getchar();

    for(i=0; i<n; i++) {
        printf("Enter %d character : ", i+1);
        scanf(" %c", &arr[i]);
    }

    printf("Characters in reverse order : ");
    for(i=n-1; i>=0; i--) {
        printf("%c", arr[i]);
    }

    return 0;
}