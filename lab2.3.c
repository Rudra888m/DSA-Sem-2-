#include<stdio.h>
#include<string.h>

struct employee {
    int id;
    char name[100];
    int salary;
};

struct organization {
    int ide;
    char nameo[100];
    struct employee e[2];
};

int main() {
    struct organization o[2];
    int i, j;

    for(i=0; i<2; i++) {
        printf("\nOrganization %d...", i+1);
        printf("\nEnter Organization ID : ");
        scanf("%d", &o[i].ide);
        getchar();

        printf("Enter Organization Name : ");
        fgets(o[i].nameo, sizeof(o[i].nameo), stdin);
        o[i].nameo[strcspn(o[i].nameo, "\n")] = '\0';

        for(j=0; j<2; j++) {
            printf("Employee %d...\n", j+1);
            printf("Enter Employee ID : ");
            scanf("%d", &o[i].e[j].id);
            getchar();

            printf("Enter Employee Name : ");
            fgets(o[i].e[j].name, sizeof(o[i].e[j].name), stdin);
            o[i].e[j].name[strcspn(o[i].e[j].name, "\n")] = '\0';

            printf("Enter Employee salary : ");
            scanf("%d", &o[i].e[j].salary);
            getchar();
        }
    }
    printf("\n---Organization Details---\n");
    for(i=0; i<2; i++) {
        printf("\nOrganization %d...\n", i+1);
        printf("Organization ID : %d\n", o[i].ide);
        printf("Organization Name : %s\n", o[i].nameo);

        for(j=0; j<2; j++) {
            printf("\n\tEmployee %d...\n", j+1);
            printf("\tEmployee ID : %d\n", o[i].e[j].id);
            printf("\tEmployee Name : %s\n", o[i].e[j].name);
            printf("\tEmployee salary : %d\n", o[i].e[j].salary);
        }
    }
    return 0;
}