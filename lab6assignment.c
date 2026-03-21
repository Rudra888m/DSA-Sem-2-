#include<stdio.h>
#include<ctype.h>
#include<string.h>

int stack[100];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    return stack[top--];
}

int eval(char exp[]) {
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == ' ') {
            i++;
            continue;
        }
        if(isdigit(exp[i])) {
            int num = 0;

            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            i--; 
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch(exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[100];
    int choice;

    do {
        printf("\nEnter postfix expression : ");
        fgets(exp, sizeof(exp), stdin);
        exp[strcspn(exp, "\n")] = '\0';

        if(strlen(exp) == 0) {
            printf("Empty input, try again.\n");
            continue;
        }

        top = -1;

        printf("Result = %d\n", eval(exp));

        printf("Do you want to continue? (1 = Yes / 0 = No) : ");
        scanf("%d", &choice);

        while(getchar() != '\n');
    } while(choice == 1);

    return 0;
}