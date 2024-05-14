#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

struct Layer {
    int in_dim;
    int out_dim;
    int in_dim_with_bias;
    struct Matrix *weights;
    struct Matrix *layer_in;
    struct Matrix *layer_out;
};

void init_layer(int in_dim, int out_dim) {
    struct Layer *layer = malloc(sizeof(struct Layer));
    layer->in_dim = in_dim;
    layer->out_dim = out_dim;
    layer->in_dim_with_bias = in_dim + 1;
    layer->weights = createRandomMatrix(out_dim, layer->in_dim_with_bias);
    layer->layer_in = createZeroMatrix(in_dim, 1);
    layer->layer_out = createZeroMatrix(out_dim, 1);
}

struct Matrix* layer_forward(struct Matrix* x) {

}

int main() {
    srand(time(NULL));

    struct Matrix *m1 = createRandomMatrix(2, 2);
    struct Matrix *m2 = createRandomMatrix(2, 3);

    printMatrix(m1);
    printMatrix(m2);

    struct Matrix *m3 = multiplyMatrices(m1, m2);
    printMatrix(m3);

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);

    return 0;
}
