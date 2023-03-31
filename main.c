#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int main()
{
    double arr1[3][3] = {{80000,8.7,91},{4,6,3},{2,6,1}};
    double arr2[3][4] = {{8,8.7,91,43},{4,6,3,2.2},{2,6,1,1.3}};
    struct Matrix *m1 = createMatrix(3,3);
    struct Matrix *m2 = createMatrix(3,4);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            setMatrix(m1, i, j, arr1[i][j]);
        }
    }

    printMat(m1);

    freeMatrix(m1);
    freeMatrix(m2);

    return 0;
}
