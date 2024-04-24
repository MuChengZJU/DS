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
#define ILLEGAL_BRACKET 2 

/**
 * @brief Convert the infix expression to postfix expression
 * 
 * @param infix (Number: 0-9(Negative allowed), Operator: + - * / ( ) [ ], End: =)
 * @param postfix (Numbers are separated by space ' ')
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
    fgets(infix, MAX_INPUT_SIZE, stdin);

    // Convert the infix expression to postfix expression
    char postfix[MAX_INPUT_SIZE];
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


