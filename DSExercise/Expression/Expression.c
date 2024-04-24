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
#include <stdio.h>

#define MAX_INPUT_SIZE 100

#define OK 0
#define ILLEGAL_INPUT 1
#define ILLEGAL_INPUT_CHARACTER 2
#define ILLEGAL_INPUT_BRACKET 3

/**
 * @brief Convert the infix expression to postfix expression
 * 
 * @param infix (Number: 0-9(Negative allowed), Operator: + - * / ( ) [ ], End: =)
 * @param postfix (Numbers and operators are separated by space ' ')
 * @return int 
 */
static int convertInfix2Postfix(char *infix, char *postfix);

/**
 * @brief Detect if the infix expression contains illegal characters (beyond numbers and opetaors) or []() dont match
 * 
 * @param infix 
 * @return int 
 */
static int illegalDetect(char *infix);

/**
 * @brief Calculate a postfix expression
 * 
 * @param postfix 
 * @return int 
 */
static int calculatePostfix(char *postfix);


/**
 * @brief 
 * 
 * @return int 
 */
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
            // TODO: Priority of [ ]
            cStackPush(&operatorStack, infix[i]);
        } else if (infix[i] == ')' || infix[i] == ']') {
            // Right Bracket
            // Pop the operators until the corresponding left bracket
            // Bracket are examined to be matched in illegalDetect
            char c;
            cStackPop(&operatorStack, &c);
            while (c != '(' || c != '[') {
                postfix[j++] = c;
                postfix[j++] = ' ';
                cStackPop(&operatorStack, &c); // Pop the ([ but dont send to postfix
            }
        } else if (infix[i] == '+' || infix[i] == '-') {
            // + -
            // Pop until the stack is empty or the top is ( [ (lower priority than * /)
            // Then push
            char c;
            while (cStackPop(&operatorStack, &c) == 0 || c != '(' || c != '[') {
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
            while (cStackPop(&operatorStack, &c) == 0 || c != '(' || c != '[' || c != '+' || c != '-') {
                postfix[j++] = c;
                postfix[j++] = ' ';
            }
            cStackPush(&operatorStack, c);
            cStackPush(&operatorStack, infix[i]);
        }

        // Iteration over, then check if the stack remain operators
        char c;
        while (cStackPop(&operatorStack, &c) == 0) {
            postfix[j++] = c;
            postfix[j++] = ' ';
        }
        postfix[j--] = '\0'; // Let the last char be \0
    }

    // Pop the remaining operators
    char c;
    int j = 0;
    while (cStackPop(&operatorStack, &c) == 0) {
        postfix[j++] = c;
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';

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
        }
    }
}