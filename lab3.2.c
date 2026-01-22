#include<stdio.h>
#include<string.h>

struct student {
    char name[100];
    int roll_no;
    char address[100];
};

int main() {
    int n;

    printf("\nEnter number of students : ");
    scanf("%d", &n);
    getchar();

    struct student s[n];
    struct student *ptr;

    ptr = s;

    printf("\n---Student Information---\n");
    for(int i=0; i<n; i++) {
        printf("\nStudent %d...\n", i+1);

        printf("Enter student name : ");
        fgets(ptr[i].name, sizeof(ptr[i].name), stdin);
        ptr[i].name[strcspn(ptr[i].name, "\n")] = '\0';

        printf("Enter student roll no. : ");
        scanf("%d", &ptr[i].roll_no);
        getchar();

        printf("Enter student address : ");
        fgets(ptr[i].address, sizeof(ptr[i].address), stdin);
        ptr[i].address[strcspn(ptr[i].address, "\n")] = '\0';
    }
    
    printf("\n\n---Student Details---\n");
    for(int i=0; i<n; i++) {
        printf("\nStudent %d...\n", i+1);
        printf("Student name : %s\n", ptr[i].name);
        printf("Student roll no. : %d\n", ptr[i].roll_no);
        printf("Student address : %s\n", ptr[i].address);
        }
    return 0;
}