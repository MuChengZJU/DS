/**
 * @file Stack.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-24
 * 
 * 
 */

#ifndef STACK_H
#define STACK_H

#define STACK_INIT_SIZE 100

/**
 * @brief (For Operators) Infix to Postfix, Postfix expression calculation stack in Expression.c
 * 
 */
typedef struct {
    char *base;
    char *top;
    int stackSize;
}charStack;

/**
 * @brief (For Numbers) Postfix expression calculation stack in Expression.c
 * 
 */
typedef struct {
    double *base;
    double *top;
    int stackSize;
}doubleStack;

/**
 * @brief Init charStack
 * 
 * @param cStack 
 * @return int 
 */
int cStackInit(charStack *cStack);

/**
 * @brief Push char to charStack
 * 
 * @param cStack 
 * @param c 
 * @return int 
 */
int cStackPush(charStack *cStack, char c);

/**
 * @brief Pop char from charStack
 * 
 * @param cStack 
 * @param c 
 * @return int 
 */
int cStackPop(charStack *cStack, char *c);

/**
 * @brief Destroy charStack
 * 
 * @param cStack 
 * @return int 
 */
int cStackDestroy(charStack *cStack);

int cStackPrint(charStack *cStack);

int cStackEmpty(charStack *cStack);


/**
 * @brief Init doubleStack
 * 
 * @param dStack 
 * @return int 
 */
int dStackInit(doubleStack *dStack);

/**
 * @brief Push double to doubleStack
 * 
 * @param dStack 
 * @param d 
 * @return int 
 */
int dStackPush(doubleStack *dStack, double d);

/**
 * @brief Pop double from doubleStack
 * 
 * @param dStack 
 * @param d 
 * @return int 
 */
int dStackPop(doubleStack *dStack, double *d);

/**
 * @brief Destroy doubleStack
 * 
 * @param dStack 
 * @return int 
 */
int dStackDestroy(doubleStack *dStack);


#endif // STACK_H