#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

double stack[MAX_SIZE];
int top = -1;

void push(double x) {
    stack[++top] = x;
}

double pop() {
    return stack[top--];
}

int is_operand(char c) {
    if (isdigit(c) || isalpha(c)) {
        return 1;
    }
    return 0;
}

double evaluate_postfix(char* exp) {
    int i;
    double op1, op2, result;
    char c;

    for (i = 0; i < strlen(exp); i++) {
        c = exp[i];

        if (is_operand(c)) {
            push((double)(c - '0'));
        } else {
            op2 = pop();
            op1 = pop();

            switch (c) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(0);
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    printf("Result: %lf\n", evaluate_postfix(exp));
    return 0;
}

