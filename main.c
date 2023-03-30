#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

int *createMatrix(size_t a, size_t b);

struct Matrix {
    int rows;
    int cols;
    int **data;
};



int main()
{
    int arr[3][3] = {{8,8,90},{4,6,3},{2,6,1}};
    struct Matrix *m = createMatrix(3,6);
    m->data[0][0] = 3;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = i+j;
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
    //struct Matrix *m = createMatrix(3,3);
    // free the memory allocated for the matrix data

    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);

    // free the memory allocated for the Matrix structure
    free(m);

    return 0;
}

int *createMatrix(size_t m, size_t n){
    //Allocates memory for a mxn matrix structure, which stores data and the values m,n
    struct Matrix *mat = (struct Matrix*) malloc(sizeof(struct Matrix));
    //allocate memory for the matrix data
    mat->data = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat->data[i] = (int*) malloc(n * sizeof(int));
    }
    mat->rows = m;
    mat->cols = n;

    return mat;
}
