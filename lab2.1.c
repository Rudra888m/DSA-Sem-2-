#include<stdio.h>
#include<string.h>

struct student {
    char name[100];
    int roll_no;
    char address[100];
};

int main() {
    struct student s1;

    printf("\nEnter name : ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = '\0';

    printf("Enter roll no. : ");
    scanf("%d", &s1.roll_no);
    getchar();

    printf("Enter Address : ");
    fgets(s1.address, sizeof(s1.address), stdin);
    s1.address[strcspn(s1.address, "\n")] = '\0';

    printf("\n---Student Details---\n");
    printf("Student Name : %s\n", s1.name);
    printf("Roll no. : %d\n", s1.roll_no);
    printf("Address : %s\n", s1.address);

    return 0;
}