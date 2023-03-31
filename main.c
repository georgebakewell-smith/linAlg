#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int main()
{
    double arr1[2][2] = {{4,3},{1,7}};
    double arr2[2][3] = {{9,4,3},{2,7,1}};
    struct Matrix *m1 = createMatrix(2,2);
    struct Matrix *m2 = createMatrix(2,3);

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

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);

    return 0;
}
