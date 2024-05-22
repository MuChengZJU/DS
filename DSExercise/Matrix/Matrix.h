/**
 * @file Matrix.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-09
 * 
 * 
 */

#ifndef MATRIX_H
#define MATRIX_H

#define MAX_MATRIX_SIZE 100

typedef struct {
    int row;    // Row number
    int col;    // Column number
    double data;  // Data
}Element; 

typedef struct
{
    int row; // Row number
    int col; // Column number
    int size; //Number of non-zero elements
    Element *data;
}Matrix;

int labMatrix();

void initMatrix(Matrix *matrix, int row, int col, int size);

void sortMatrix(Matrix *matrix);

void printMatrix(Matrix *matrix);

void addMatrix(Matrix *matrix1, Matrix *matrix2, Matrix *result);

#endif // MATRIX_H
