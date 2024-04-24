#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct Node {
    int isOperator;
    union {
        int value;
        char op;
    };
    struct Node* next;
} Node;

// Õ»²Ù×÷
Node* push(Node** top, int isOperator, int value, char op) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isOperator = isOperator;
    if (isOperator) {
        newNode->op = op;
    } else {
        newNode->value = value;
    }
    newNode->next = *top;
    *top = newNode;
    return newNode;
}

Node* pop(Node** top) {
    if (*top == NULL) {
        return NULL;
    }
    Node* temp = *top;
    *top = (*top)->next;
    return temp;
}

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '[':
        case ']':
        case '(':
        case ')':
            return 0;
        default:
            return -1;
    }
}

void infix2postfix(char* infix, Node** postfix) {
    Node* stack = NULL;
    int i, j = 0, leftParentheses = 0, rightParentheses = 0;
    int num = 0, isNum = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i])) {
            num = num * 10 + (infix[i] - '0');
            isNum = 1;
        } else {
            if (isNum) {
                push(postfix, 0, num, 0);
                num = 0;
                isNum = 0;
            }
            if (infix[i] == '[') {
                leftParentheses++;
                push(&stack, 1, 0, infix[i]);
            } else if (infix[i] == ']') {
                rightParentheses++;
                if (rightParentheses > leftParentheses) {
                    printf("Error: Unmatched parentheses.\n");
                    return;
                }
                while (stack != NULL && stack->op != '[') {
                    push(postfix, 1, 0, stack->op);
                    Node* temp = pop(&stack);
                    free(temp);
                }
                if (stack != NULL && stack->op == '[') {
                    Node* temp = pop(&stack);
                    free(temp);
                }
            } else if (infix[i] == '(') {
                leftParentheses++;
                push(&stack, 1, 0, infix[i]);
            } else if (infix[i] == ')') {
                rightParentheses++;
                if (rightParentheses > leftParentheses) {
                    printf("Error: Unmatched parentheses.\n");
                    return;
                }
                while (stack != NULL && stack->op != '(') {
                    push(postfix, 1, 0, stack->op);
                    Node* temp = pop(&stack);
                    free(temp);
                }
                if (stack != NULL && stack->op == '(') {
                    Node* temp = pop(&stack);
                    free(temp);
                }
            } else {
                if (getPriority(infix[i]) == -1) {
                    printf("Error: Invalid character '%c' in the expression.\n", infix[i]);
                    return;
                }
                while (stack != NULL && getPriority(stack->op) >= getPriority(infix[i])) {
                    if (stack->op == '/' && infix[i] == '0') {
                        printf("Error: Division by zero.\n");
                        return;
                    }
                    push(postfix, 1, 0, stack->op);
                    Node* temp = pop(&stack);
                    free(temp);
                }
                push(&stack, 1, 0, infix[i]);
            }
        }
    }

    if (isNum) {
        push(postfix, 0, num, 0);
    }

    if (leftParentheses != rightParentheses) {
        printf("Error: Unmatched parentheses.\n");
        return;
    }

    while (stack != NULL) {
        push(postfix, 1, 0, stack->op);
        Node* temp = pop(&stack);
        free(temp);
    }
}

int lab3() {
    char infix[MAX_EXPRESSION_LENGTH];
    Node* postfix = NULL;

    printf("Please enter the infix expression (end with '=' and press Enter): ");
    fgets(infix, MAX_EXPRESSION_LENGTH, stdin);

    // È¥³ýÄ©Î²µÄ»»ÐÐ·û
    infix[strlen(infix) - 2] = '\0';

    infix2postfix(infix, &postfix);

    printf("Postfix expression:\n");
    Node* current = postfix;
    while (current != NULL) {
        if (current->isOperator) {
            printf("%c ", current->op);
        } else {
            printf("%d ", current->value);
        }
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("\n");

    return 0;
}