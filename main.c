#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int main()
{
    double arr1[3][3] = {{4,3,1},{1,7,4},{4,0,3}};
    double arr2[3][1] = {{1.5},{2},{3}};
    struct Matrix *m1 = createMatrix(3,3);
    struct Matrix *m2 = createMatrix(3,1);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            setMatrix(m1, i, j, arr1[i][j]);
        }
    }

    for (int i = 0; i < m2->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            setMatrix(m2, i, j, arr2[i][j]);
        }
    }
    struct Matrix *m3 = multMat(m1,m2);
    printMat(m3);
    printf("\n%f",normSquare(m3));

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);

    return 0;
}
