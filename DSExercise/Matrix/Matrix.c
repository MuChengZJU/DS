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
    if (choice == 0) {
        returnValue = EXIT;
    } else if (choice == 1) {
        // Addition

        // Input matrix 1
        int row1, col1, size1;
        Matrix *matrix1 = (Matrix *)malloc(sizeof(Matrix));
        printf("Enter the row, column and non-zero count of matrix 1: \n");
        scanf("%d %d %d", &row1, &col1, &size1);
        printf("Enter the elements of matrix 1 (i, j, value): \n");
        initMatrix(matrix1, row1, col1, size1);
        sortMatrix(matrix1);
        printf("Matrix 1: \n");
        printMatrix(matrix1);
        // Input matrix 2
        int row2, col2, size2;
        Matrix *matrix2 = (Matrix *)malloc(sizeof(Matrix));
        printf("Enter the row, column and non-zero count of matrix 2: \n");
        scanf("%d %d %d", &row2, &col2, &size2);
        printf("Enter the elements of matrix 2 (i, j, value): \n");
        initMatrix(matrix2, row2, col2, size2);
        sortMatrix(matrix2);
        printf("Matrix 2: \n");
        printMatrix(matrix2);
        // Calculate the sum
        if (row1 != row2) {
            printf("row1 != row2\n");
            returnValue = INVALID_INPUT;
        } else if (col1 != col2) {
            printf("col1 != col2\n");
            returnValue = INVALID_INPUT;
        } else{
            Matrix *result = (Matrix *)malloc(sizeof(Matrix));
            addMatrix(matrix1, matrix2, result);
            printf("Result: \n");
            printMatrix(result);
            returnValue = OK;
        }
    } else if (choice == 2) {
        // Subtraction
        returnValue = OK;
    } else if (choice == 3) {
        // Multiplication
        returnValue = OK;
    } else if (choice == 4) {
        // Transpose
        returnValue = OK;
    } else {
        printf("Invalid input\n");
        returnValue = INVALID_INPUT;
    }

    return returnValue;
}

void initMatrix(Matrix *matrix, int row, int col, int size) {
    matrix->row = row;
    matrix->col = col;
    matrix->size = size;
    matrix->data = (Element *)malloc(sizeof(Element) * size);
    if (matrix->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        scanf("%d %d %lf", &matrix->data[i].row, &matrix->data[i].col, &matrix->data[i].data);
    }

}

void sortMatrix(Matrix *matrix) {
    // Sort the matrix by row and column
    for (int i = 0; i < matrix->size; i++) {
        for (int j = i + 1; j < matrix->size; j++) {
            if (matrix->data[i].row > matrix->data[j].row || (matrix->data[i].row == matrix->data[j].row && matrix->data[i].col > matrix->data[j].col)) {
                Element temp = matrix->data[i];
                matrix->data[i] = matrix->data[j];
                matrix->data[j] = temp;
            }
        }
    }
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->size; i++) {
        printf("%d, %d, %lf\n", matrix->data[i].row, matrix->data[i].col, matrix->data[i].data);
    }
}

void addMatrix(Matrix *matrix1, Matrix *matrix2, Matrix *result) {
    // Initialize the result matrix
    result->row = matrix1->row;
    result->col = matrix1->col;
    result->size = 0;
    result->data = (Element *)malloc(sizeof(Element) * (matrix1->size + matrix2->size));
    if (result->data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Add the two matrices
    int i = 0, j = 0;
    while (i < matrix1->size && j < matrix2->size) {
        if (matrix1->data[i].row < matrix2->data[j].row || (matrix1->data[i].row == matrix2->data[j].row && matrix1->data[i].col < matrix2->data[j].col)) {
            result->data[result->size] = matrix1->data[i];
            i++;
        } else if (matrix1->data[i].row > matrix2->data[j].row || (matrix1->data[i].row == matrix2->data[j].row && matrix1->data[i].col > matrix2->data[j].col)) {
            result->data[result->size] = matrix2->data[j];
            j++;
        } else {
            result->data[result->size].row = matrix1->data[i].row;
            result->data[result->size].col = matrix1->data[i].col;
            result->data[result->size].data = matrix1->data[i].data + matrix2->data[j].data;
            i++;
            j++;
        }
        result->size++;
    }
}