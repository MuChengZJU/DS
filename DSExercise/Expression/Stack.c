/**
 * @file Stack.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-24
 * 
 * 
 */
#include "Stack.h"
#include <stddef.h>
#include <stdlib.h>

int cStackInit(charStack *cStack) {
    cStack->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
    if (!cStack->base) {
        return -1;
    }
    cStack->top = cStack->base;
    cStack->stackSize = STACK_INIT_SIZE;
    return 0;
}

int cStackPush(charStack *cStack, char c){
    if (cStack->top - cStack->base >= cStack->stackSize) {
        cStack->base = (char *)realloc(cStack->base, (cStack->stackSize + STACK_INIT_SIZE) * sizeof(char));
        if (!cStack->base) {
            return -1;
        }
        cStack->top = cStack->base + cStack->stackSize;
        cStack->stackSize += STACK_INIT_SIZE;
    }
    *cStack->top++ = c;
    return 0;
}

int cStackPop(charStack *cStack, char *c) {
    if (cStack->top == cStack->base) {
        return -1;
    }
    *c = *--cStack->top;
    return 0;
}

int cStackDestroy(charStack *cStack) {
    free(cStack->base);
    cStack->base = NULL;
    cStack->top = NULL;
    cStack->stackSize = 0;
    return 0;
}

int dStackInit(doubleStack *dStack) {
    dStack->base = (double *)malloc(STACK_INIT_SIZE * sizeof(double));
    if (!dStack->base) {
        return -1;
    }
    dStack->top = dStack->base;
    dStack->stackSize = STACK_INIT_SIZE;
    return 0;
}

int dStackPush(doubleStack *dStack, double d) {
    if (dStack->top - dStack->base >= dStack->stackSize) {
        dStack->base = (double *)realloc(dStack->base, (dStack->stackSize + STACK_INIT_SIZE) * sizeof(double));
        if (!dStack->base) {
            return -1;
        }
        dStack->top = dStack->base + dStack->stackSize;
        dStack->stackSize += STACK_INIT_SIZE;
    }
    *dStack->top++ = d;
    return 0;
}

int dStackPop(doubleStack *dStack, double *d) {
    if (dStack->top == dStack->base) {
        return -1;
    }
    *d = *--dStack->top;
    return 0;
}

int dStackDestroy(doubleStack *dStack) {
    free(dStack->base);
    dStack->base = NULL;
    dStack->top = NULL;
    dStack->stackSize = 0;
    return 0;
}
