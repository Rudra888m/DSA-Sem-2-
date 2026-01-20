#include<stdio.h>
#include<string.h>

struct book {
    int book_id;
    char title[100];
    char author[100];
    float price;
};

struct library {
    char name[100];
    int library_id;
    struct book b[3];
};

int main() {
    struct library l[2];
    int i, j;

    printf("\n---Welcome---\n\n");
    for(i=0; i<2; i++) {
        
        printf("Enter %d library name : ", i+1);
        fgets(l[i].name, sizeof(l[i].name), stdin);
        l[i].name[strcspn(l[i].name, "\n")] = '\0';

        printf("Enter %d library ID : ", i+1);
        scanf("%d", &l[i].library_id);
        getchar();

        printf("\n");

        for(j=0; j<3; j++) {

            printf("\tEnter %d book ID : ", j+1);
            scanf("%d", &l[i].b[j].book_id);
            getchar();

            printf("\tEnter %d book title : ", j+1);
            fgets(l[i].b[j].title, sizeof(l[i].b[j].title), stdin);
            l[i].b[j].title[strcspn(l[i].b[j].title, "\n")] = '\0';

            printf("\tEnter %d author name : ", j+1);
            fgets(l[i].b[j].author, sizeof(l[i].b[j].author), stdin);
            l[i].b[j].author[strcspn(l[i].b[j].author, "\n")] = '\0';

            printf("\tEnter %d price : ", j+1);
            scanf("%f", &l[i].b[j].price);
            getchar();

            printf("\n");
        }
    }

    printf("---Library Details---\n\n");
    for(i=0; i<2; i++) {
        
        printf("Library name : %s\n", l[i].name);
        printf("Library ID : %d\n", l[i].library_id);
        printf("\n");

        for(j=0; j<3; j++) {

            printf("%d Book", j+1);
            printf("\tBook ID : %d\n", l[i].b[j].book_id);
            printf("\tBook title : %s\n", l[i].b[j].title);
            printf("\tAuthor name : %s\n", l[i].b[j].author);
            printf("\tPrice : %f\n\n", l[i].b[j].price);
        }
    }

    int id_input, found = 0;
    printf("Enter book ID to search : ");
    scanf("%d", &id_input);

    for(i=0; i<2; i++) {
        for(j=0; j<3; j++) {
            if(id_input == l[i].b[j].book_id) {
                found = 1;
                printf("\tLibrary name : %s\n", l[i].name);
                printf("\tBook ID : %d\n", l[i].b[j].book_id);
                printf("\tBook title : %s\n", l[i].b[j].title);
                printf("\tAuthor name : %s\n", l[i].b[j].author);
                printf("\tPrice : %f\n\n", l[i].b[j].price);

                break;
            }
        }
    }
    if(found == 0) {
        printf("Book not found!\n");
    }

    float sum1 = 0, sum2 = 0, max1 = l[0].b[0].price, max2 = l[1].b[0].price;
    char title1[100], title2[100]; 

    strcpy(title1, l[0].b[0].title);
    strcpy(title2, l[1].b[0].title);
    for(i=0; i<3; i++) {
        sum1 += l[0].b[i].price;
        sum2 += l[1].b[i].price;

        if(l[0].b[i].price > max1){
            max1 = l[0].b[i].price;
            strcpy(title1, l[0].b[i].title);
        }
        if(l[1].b[i].price > max2) {
            max2 = l[1].b[i].price;
            strcpy(title2, l[1].b[i].title);
        }
    }

    printf("\nTotal value of library-1 is %.2f.\n", sum1);
    printf("Total value of library-2 is %.2f.\n", sum2);

    printf("\nMost expensive book in library-1 : \n");
    printf("Book title : %s\n", title1);
    printf("Book price : %.2f\n", max1);

    printf("\nMost expensive book in library-2 : \n");
    printf("Book title : %s\n", title2);
    printf("Book price : %.2f\n", max2);

    return 0;
}