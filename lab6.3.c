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

int isbalanced(char exp[]) {
    int i=0;

    while(exp[i]) {
        if(exp[i] == ' ') {
            i++;
            return 0;
        }

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);

        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1)
                return 0;
            
            char topchar = pop();
            if((exp[i] == ')' && topchar != '(') || (exp[i] == '}' && topchar != '{') || (exp[i] == ']' && topchar != '[')) 
                return 0;
        }
        i++;
    }
    if(top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char exp[100];

    printf("\nEnter expression : ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    if(isbalanced(exp))
        printf("Balanced\n");
    else 
        printf("Not Balanced\n");

    return 0;
}