#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int main()
{
    double arr[3][3] = {{8,8.7,91},{4,6,3},{2,6,1}};
    struct Matrix *m = createMatrix(3,3);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            setMatrix(m, i, j, arr[i][j]);
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
    freeMatrix(m);

    return 0;
}
