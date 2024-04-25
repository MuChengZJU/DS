/**
 * @file Expression.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-24
 * 
 * 
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Stack.h"

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
static int calculatePostfix(char *postfix, double *result);


/**
 * @brief 
 * 
 * @return int 
 */
int Expression(void);

#endif //EXPRESSION_H