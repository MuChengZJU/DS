/**
 * @file Expression.c
 * @author MuChengZJU (QuChuanyang@ZJU.edu.cn)
 * @brief https://jnnls4etqn.feishu.cn/wiki/NAOLwWrtsiZuxMk32DccU3DYn1c
 * @version 0.1
 * @date 2024-04-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Stack.h"
#include "Expression.h"
#include <stdio.h>

#ifndef DEBUG
#define DEBUG 0
#endif

int Expression(void) {
    // Input the infix expression
    printf("Please input the infix expression:(end with = and enter)\n");
    char infix[MAX_INPUT_SIZE];
    char postfix[MAX_INPUT_SIZE];
    fgets(infix, MAX_INPUT_SIZE, stdin);

    // Convert the infix expression to postfix expression
    if (illegalDetect(infix)) {
        printf("Illegal input!\n");
        return ILLEGAL_INPUT;
    }
    convertInfix2Postfix(infix, postfix);

#if DEBUG
    printf("The postfix expression is: %s\n", postfix);
#endif
    printf("The postfix expression is: %s\n", postfix);

    // Calculate the postfix expression
    calculatePostfix(postfix);

    // Output the result
    printf("The result is: %s\n", postfix);

    return OK;
}


static int illegalDetect (char *infix) {
    // Illegal Charcters (Not numbers or operators)
    // Iterate over the infix expression, detcting illegal characters
    for (int i = 0; infix[i] != '='; i++) {
        if (! ((infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.'\
        || infix[i] == '+' || infix[i] == '-' \
        || infix[i] == '*' || infix[i] == '/' \
        || infix[i] == '(' || infix[i] == ')' \
        || infix[i] == '[' || infix[i] == ']' )) {
            return ILLEGAL_INPUT_CHARACTER;
        }
    }

    // Illegal Brackets
    charStack bracketStack;
    cStackInit(&bracketStack);
    for (int i = 0; infix[i] != '='; i++) {
        if (infix[i] == '(' || infix[i] == '[') {
            cStackPush(&bracketStack, infix[i]);
        }
        if (infix[i] == ')' || infix[i] == ']') {
            char c;
            cStackPop(&bracketStack, &c);
            if (c == '(' && infix[i] != ')') {
                return ILLEGAL_INPUT_BRACKET;
            }
            if (c == '[' && infix[i] != ']') {
                return ILLEGAL_INPUT_BRACKET;
            }
        }
    }

    // Devide By 0
    // This situation will be handled when calculation the postfix expression

    return OK;
}

static int convertInfix2Postfix(char *infix, char *postfix) {
    // Init the operator stack
    charStack operatorStack;
    cStackInit(&operatorStack);

    // Iterate over the infix expression, converting it to postfix expression
    for (int i = 0, j = 0; infix[i] != '='; i++) {

// #if DEBUG
    printf("The postfix expression is: %s\n", postfix);
    printf("The operator stack is: ");
    cStackPrint(&operatorStack);
// #endif

        if (infix[i] >= '0' && infix[i] <= '9') {
            // Number or .
            // Directly send to postfix
            // Using loop to get a complete number
            // TODO: Negative number
            while ( (infix[i] >= '0' && infix[i] <= '9') || infix[i] == '.') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (infix[i] == '(' || infix[i] == '[') {
            // Left Bracket
            // Directly push to operator stack
            cStackPush(&operatorStack, infix[i]);
        } else if (infix[i] == ')' || infix[i] == ']') {
            // Right Bracket
            // Pop the operators until the corresponding left bracket
            // Bracket are examined to be matched in illegalDetect
            char c;
            cStackPop(&operatorStack, &c);
            while (c != '(' && c != '[') {//TODO: cStackPop(&operatorStack, &c) == 0
                postfix[j++] = c;
                postfix[j++] = ' ';
                cStackPop(&operatorStack, &c); // Pop the ([ but dont send to postfix
            }
        } else if (infix[i] == '+' || infix[i] == '-') {
            // + -
            // Pop until the stack is empty or the top is ( [ (lower priority than * /)
            // Then push
            char c;
            while (cStackPop(&operatorStack, &c) == 0 && c != '(' && c != '[') {
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPush(&operatorStack, c);
            cStackPush(&operatorStack, infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/') {
            // * /
            // Pop until the stack is empty or the top is ( [  + - (lower priority than * /)
            // Then push
            char c;
            while (cStackPop(&operatorStack, &c) == 0 && c != '(' && c != '[' && c != '+' && c != '-') {
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPush(&operatorStack, c);
            cStackPush(&operatorStack, infix[i]);
        }

    }

    // Pop the remaining operators
    char c;
    int j = 0;
    while (cStackPop(&operatorStack, &c) == 0) {
        postfix[j++] = c;
        postfix[j++] = ' ';
    }
    postfix[j--] = '\0'; // Let the last char be \0

    return OK;
}

static int calculatePostfix(char *postfix) {
    // Init the number stack
    doubleStack numberStack;
    dStackInit(&numberStack);

    // Iterate over the postfix expression, calculating it
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            // Number
            // Directly push to number stack
            double d = 0;
            while (postfix[i] >= '0' && postfix[i] <= '9') {
                d = d * 10 + postfix[i] - '0';
                i++;
            }
            if (postfix[i] == '.') {
                i++;
                double decimal = 0.1;
                while (postfix[i] >= '0' && postfix[i] <= '9') {
                    d += (postfix[i] - '0') * decimal;
                    decimal /= 10;
                    i++;
                }
            }
            dStackPush(&numberStack, d);
        } else if (postfix[i] == ' ') {
            // Space
            // Skip
        } else {
            // Operator
            // Pop two numbers and calculate
            double d1, d2;
            dStackPop(&numberStack, &d1);
            dStackPop(&numberStack, &d2);
            switch (postfix[i]) {
            case '+':
                dStackPush(&numberStack, d2 + d1);
                break;
            case '-':
                dStackPush(&numberStack, d2 - d1);
                break;
            case '*':
                dStackPush(&numberStack, d2 * d1);
                break;
            case '/':
                if (d1 == 0) {
                    printf("Divide by 0!\n");
                    return ILLEGAL_INPUT;
                }
                dStackPush(&numberStack, d2 / d1);
                break;
            default:
                break;
            }
        }
    }

    // Pop the result
    double result;
    dStackPop(&numberStack, &result);
    sprintf(postfix, "%lf", result);

    return OK;
}