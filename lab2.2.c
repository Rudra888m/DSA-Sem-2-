#include<stdio.h>
#include<string.h>

struct student {
    char name[100];
    int roll_no;
    char address[100];
};

int main() {
    struct student s[5];
    int i;

    for(i=0; i<5; i++) {
        printf("\nEnter %d student name : ", i+1);
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Enter %d student roll no. : ", i+1);
        scanf("%d", &s[i].roll_no);
        getchar();

        printf("Enter %d student Address : ", i+1);
        fgets(s[i].address, sizeof(s[i].address), stdin);
        s[i].address[strcspn(s[i].address, "\n")] = '\0';
    }
    
    printf("\n---Student Details---\n");
    for(i=0; i<5; i++) {
        printf("%d Student Name : %s\n",i+1, s[i].name);
        printf("%d Roll no. : %d\n",i+1, s[i].roll_no);
        printf("%d Address : %s\n",i+1, s[i].address);
    }
    return 0;
}