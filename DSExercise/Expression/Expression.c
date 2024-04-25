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
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

#define OK 0
#define ILLEGAL_INPUT_CHARACTER 2
#define ILLEGAL_INPUT_BRACKET 3
#define ILLEGAL_ZERO 4

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
    int illegalCode = illegalDetect(infix);
    if (illegalCode != OK) {
        switch (illegalCode) {
        case ILLEGAL_INPUT_BRACKET:
            printf("Illegal Brackets!\n");
            break;
        case ILLEGAL_INPUT_CHARACTER:
            printf("Illegal Characters!\n");
            break;
        default:
            break;
        }
        return illegalCode;
    }

    negative2zero(infix);

    convertInfix2Postfix(infix, postfix);

// #if DEBUG
    printf("The postfix expression is: %s\n", postfix);
// #endif

    // Calculate the postfix expression
    double result;
    if (calculatePostfix(postfix, &result) != OK) {
        printf("Cant devide by 0!\n");
        return ILLEGAL_ZERO;
    }

    // Output the result
    printf("The result is: %lf\n", result);

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
    if (!cStackEmpty(&bracketStack)) {
        return ILLEGAL_INPUT_BRACKET;
    }
    cStackDestroy(&bracketStack);

    // Devide By 0
    // This situation will be handled when calculation the postfix expression

    return OK;
}

static int convertInfix2Postfix(char *infix, char *postfix) {
    // Init the operator stack
    charStack operatorStack;
    cStackInit(&operatorStack);

    int j = 0;
    // Iterate over the infix expression, converting it to postfix expression
    for (int i = 0; infix[i] != '='; i++) {
        // if (infix[i] == '-') {
        //     // Check Negative Number
        //     if (i == 0 || infix[i-1] == '(' || infix[i-1] == '[') {
        //         // Negative Number
        //         // Directly push to postfix
        //         postfix[j++] = infix[i++];
        //     }
        // }
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
            // cStackPop(&operatorStack, &c);
            // while (c != '(' && c != '[') {//TODO: cStackPop(&operatorStack, &c) == 0
            //     postfix[j++] = c;
            //     postfix[j++] = ' ';
            //     cStackPop(&operatorStack, &c); // Pop the ([ but dont send to postfix
            // }
            while ('(' != *(operatorStack.top-1) && '[' != *(operatorStack.top-1)) {
                cStackPop(&operatorStack, &c);
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPop(&operatorStack, &c); // Pop the ([ but dont send to postfix
        } else if (infix[i] == '+' || infix[i] == '-') {
            // + -
            // Pop until the stack is empty or the top is ( [ (lower priority than * /)
            // Then push
            char c;
            // while (cStackPop(&operatorStack, &c) == 0 && c != '(' && c != '[') {
            //     postfix[j++] = c;
            //     postfix[j++] = ' ';
            // }
            // cStackPush(&operatorStack, c);
            // cStackPush(&operatorStack, infix[i]);
            while ( !cStackEmpty(&operatorStack) && '(' != *(operatorStack.top-1) && '[' != *(operatorStack.top-1) ) {
                cStackPop(&operatorStack, &c);
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPush(&operatorStack, infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/') {
            // * /
            // Pop until the stack is empty or the top is ( [  + - (lower priority than * /)
            // Then push
            char c;
            // while (cStackPop(&operatorStack, &c) == 0 && c != '(' && c != '[' && c != '+' && c != '-') {
            //     postfix[j++] = c;
            //     postfix[j++] = ' ';
            // }
            // cStackPush(&operatorStack, c);
            // cStackPush(&operatorStack, infix[i]);
            while ( !cStackEmpty(&operatorStack) && '(' != *(operatorStack.top-1) && '[' != *(operatorStack.top-1) && '+' != *(operatorStack.top-1) && '-' != *(operatorStack.top-1) ) {
                cStackPop(&operatorStack, &c);
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPush(&operatorStack, infix[i]);
        }
#if DEBUG
    printf("The current char is: infix[%d]=%c\n", i, infix[i]);
    printf("The postfix expression is: %s\n", postfix);
    printf("The operator stack is: ");
    cStackPrint(&operatorStack);
#endif
    }

    // Pop the remaining operators
    char c;
    while (cStackPop(&operatorStack, &c) == 0) {
        postfix[j++] = c;
        postfix[j++] = ' ';
    }
    postfix[j--] = '\0'; // Let the last char be \0

#if DEBUG
    printf("The postfix expression is: %s\n", postfix);
    cStackPrint(&operatorStack);
#endif

    return OK;
}

static int calculatePostfix(char *postfix, double *result) {
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
                    return ILLEGAL_ZERO;
                }
                dStackPush(&numberStack, d2 / d1);
                break;
            default:
                break;
            }
        }
    }

    // Pop the result
    // double result;
    dStackPop(&numberStack, result);
    // sprintf(postfix, "%lf", result);

    return OK;
}

static int negative2zero (char *infix) {
    // Prefix negative numbers with 0 for minus sign
    for (int i = 0; infix[i] != '='; i++) {
        if (infix[i] == '-') {
            if (i == 0 || infix[i-1] == '(' || infix[i-1] == '[') {
                for (int j = strlen(infix); j > i; j--) {
                    infix[j] = infix[j-1];
                }
                infix[i] = '0';
            }
        }
    }

// #if DEBUG   // Debug
    printf("The negative2zero infix expression is: %s\n", infix);
// #endif

    return OK;
}