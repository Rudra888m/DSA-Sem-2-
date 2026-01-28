#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int n;
    printf("\n");
    printf("Enter total numbers of names : ");
    scanf("%d", &n);
    getchar();

    char *names[n];
    for(int i=0; i<n; i++) {
        printf("Enter %d name : ", i+1);
        names[i] = malloc(50 * sizeof(char));
        fgets(names[i], 50, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("\nNames of all students : \n");
    for(int i=0; i<n; i++) {
        printf("%d. %s\n", i+1, names[i]);
        free(names[i]);
    }

    return 0;
}