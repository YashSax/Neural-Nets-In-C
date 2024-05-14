#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_normal() {
    double u1 = (double)rand() / (double)RAND_MAX; // Uniform random number between 0 and 1
    double u2 = (double)rand() / (double)RAND_MAX; // Uniform random number between 0 and 1

    // Box-Muller transform to generate a random number from a standard normal distribution
    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return z;
}

struct Matrix* createMatrix(int numRows, int numCols) {
    struct Matrix *m = malloc(sizeof(struct Matrix));
    m->numRows = numRows;
    m->numCols = numCols;

    m->data = malloc(sizeof(double) * numCols * numRows);
    if (m->data == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    return m;
}

void freeMatrix(struct Matrix* m) {
    free(m->data);
    free(m);
}

struct Matrix* createZeroMatrix(int numRows, int numCols) {
    struct Matrix *m = createMatrix(numRows, numCols);
    for (int i = 0; i < numRows * numCols; i++) {
        m->data[i] = 0;
    }
    return m;
}

struct Matrix* createRandomMatrix(int numRows, int numCols) {
    struct Matrix *m = createMatrix(numRows, numCols);
    for (int i = 0; i < numRows * numCols; i++) {
        m->data[i] = rand_normal();
    }
    return m;
}

void printMatrix(struct Matrix* m) {
    for (int i = 0; i < m->numRows; i++) {
        for (int j = 0; j < m->numCols; j++) {
            printf("%f ", m->data[i * m->numCols + j]);
        }
        printf("\n");
    }
}

struct Matrix* multiplyMatrices(struct Matrix* m1, struct Matrix* m2) {
    if (m1->numCols != m2->numRows) {
        return NULL;
    }
    struct Matrix *result = createZeroMatrix(m1->numRows, m2->numCols);
    for (int i = 0; i < result->numRows; i++) {
        for (int j = 0; j < result->numCols; j++) {
            for (int k = 0; k < m1->numCols; k++) {
                result->data[i * result->numCols + j] = result->data[i * result->numCols + j] + m1->data[i * m1->numCols + k] * m2->data[k * m2->numCols+ j];
            }
        }
    }
    return result;
}