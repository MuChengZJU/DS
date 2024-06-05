/**
 * @file Matrix.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-09
 * 
 * 
 */

#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define EXIT 1
#define INVALID_INPUT 2


int labMatrix() {
    int returnValue = OK;
    // User menu
    printf("Select a function:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose\n");
    printf("0. Exit\n");

    // User input
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        returnValue = EXIT;
        break;
    case 1:
        // Addition
        {
        int row1, col1;     
        printf("Enter the row and column number of matrix 1: \n");
        scanf("%d %d", &row1, &col1);
        
        returnValue = OK;
        }
        
        break;
    case 2:
        // Subtraction
        returnValue = OK;
        break;
    case 3:
        // Multiplication
        returnValue = OK;
        break;
    case 4:
        // Transpose
        returnValue = OK;
        break;
    default:
        printf("Invalid input\n");
        returnValue = INVALID_INPUT;
        break;
    }

    return returnValue;
}