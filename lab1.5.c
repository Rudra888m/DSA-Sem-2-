#include<stdio.h>

int main() {
    int mat1[10][10], mat2[10][10], ans[10][10];
    int n, i, j, k;

    printf("Enter the order of the matrix : ");
    scanf("%d", &n);

    printf("\nEnter elements of first matrix : \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++){
            printf("Enter element [%d][%d] : ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix : \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++){
            printf("Enter element [%d][%d] : ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            ans[i][j] = 0;
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            for(k=0; k<n; k++) {
                ans[i][j] += mat1[i][k] * mat2[k][j];            }
        }
    }

    printf("Resultant matrix after multiplication : \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}