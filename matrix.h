//
// Created by vente on 5/14/2024.
//

#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

struct Matrix {
    double *data; // Stored in a numRows * numCols length array
    int numRows;
    int numCols;
};

double rand_normal();
struct Matrix* createMatrix(int numRows, int numCols);
void freeMatrix(struct Matrix* m);
struct Matrix* createZeroMatrix(int numRows, int numCols);
struct Matrix* createRandomMatrix(int numRows, int numCols);
void printMatrix(struct Matrix* m);
struct Matrix* multiplyMatrices(struct Matrix* m1, struct Matrix* m2);

#endif //MAIN_C_MATRIX_H
