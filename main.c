#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int main()
{
    double arr1[3][1] = {{4},{1},{4}};
    double arr2[3][1] = {{1},{2},{3.6}};
    struct Matrix *m1 = createMatrix(3,1);
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

    printMat(m1);
    printf("\n");

    printMat(m2);
    printf("\n\n%f",dot(m1,m2));


    freeMatrix(m1);
    freeMatrix(m2);
    //freeMatrix(m3);

    return 0;
}
