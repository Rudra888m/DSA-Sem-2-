#include<stdio.h>
#include<ctype.h>

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
        if(isdigit(exp[i]))
            push(exp[i] - '0');
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
    char exp1[] = "2 3 1 * + 9 -";
    char exp2[] = "2 2 + 2 / 5 * 7 +";

    printf("Result 1 : %d\n", eval(exp1));
    top = -1;
    printf("Result 2 : %d\n", eval(exp2));

    return 0;
}