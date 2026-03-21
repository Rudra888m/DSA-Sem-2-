#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main()
{
    char exp[100], result[100];
    int i = 0, j = 0;

    printf("\nEnter infix expression : ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    while (exp[i] != '\0')
    {
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }
        if (isalnum(exp[i]))
            result[j++] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
                result[j++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && (precedence(stack[top]) > precedence(exp[i])) || (precedence(stack[top]) == precedence(exp[i]) && exp[i] != '^'))
            {
                result[j++] = pop();
            }
            push(exp[i]);
        }
        i++;
    }
    while (top != -1)
        result[j++] = pop();

    result[j] = '\0';

    printf("Postfix : %s\n", result);

    return 0;
}