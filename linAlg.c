#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include "linAlg.h"

struct Matrix *multMat(struct Matrix *mat1, struct Matrix *mat2){
    //Takes in pointers to two matrices, multiplies them together, creates a third matrix, stores and returns result.
    double sum;
    if(mat1->cols==mat2->rows){
        struct Matrix *mat3 = createMatrix(mat1->rows,mat2->cols);
        for(int i=0;i<mat1->rows;i++){
            for(int j=0;j<mat2->cols;j++){
                sum = 0;
                for(int k=0;k<mat1->cols;k++){
                    sum += mat1->data[i][k]*mat2->data[k][j];
                }
                mat3->data[i][j] = sum;
            }
        }
        return mat3;
    } else{
        printf("Matrix dimensions not compatible for matrix multiplication.\n");
        return NULL;
    }
}

void printMat(struct Matrix *mat){
    //Takes a pointer to a matrix structure and prints
    for(int i=0;i<mat->rows;i++){
        for(int j=0;j<mat->cols;j++){
            printf("%f\t",mat->data[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(struct Matrix *mat){
// free the memory allocated for the matrix data

    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);

    // free the memory allocated for the Matrix structure
    free(mat);
}

struct Matrix *createMatrix(size_t m, size_t n){
    //Allocates memory for a mxn matrix structure, which stores data and the values m,n
    struct Matrix *mat = (struct Matrix*) malloc(sizeof(struct Matrix));
    //Initialise rows and cols to 0
    mat->rows = 0;
    mat->cols = 0;
    //allocate memory for the matrix data
    mat->data = (double**) malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        mat->data[i] = (double*) malloc(n * sizeof(double));
    }
    mat->rows = m;
    mat->cols = n;

    return mat;
}

void setMatrix(struct Matrix *mat, const int i, const int j, double x){
    //Sets i,j element of matrix to x
    mat->data[i][j] = x;
}

struct Matrix *scalarMat(double a, struct Matrix *mat){
    //Takes in scalar and matrix and returns pointer to the matrix multiplied by the scalar
    struct Matrix *result = createMatrix(mat->rows,mat->cols);
    for(int i=0;i<mat->rows;i++){
        for(int j=0;j<mat->cols;j++)
        result->data[i][j] = a*mat->data[i][j];
    }
    return result;
}

double dot(double array1[], double array2[], size_t lenArr){
//Takes in two arrays and returns the dot product
double result = 0;

for(int i=0;i<lenArr;i++){
   result += array1[i]*array2[i];
}
return result;

}

struct Matrix *powMatEl(double y, struct Matrix *mat){
    //Calculates element wise exponentiation of mat^y
    struct Matrix *result = createMatrix(mat->rows,mat->cols);
    for(int i=0;i<mat->rows;i++){
            for(int j=0;j<mat->cols;j++){
                result->data[i][j] = pow(mat->data[i][j],y);
            }
    }

    return result;
}

double normSquare(struct Matrix *vec){
    //Calculates norm square of a vector and returns as scalar
    if(vec->rows != 1 && vec->cols !=1){
        printf("Cannot perform normSquare(). One of matrix dimensions must be zero.\n");
        return -1;

    } else{
        double result = 0;
        if(vec->rows==1){
            for(int i=0;i<vec->cols;i++){
                result += vec->data[0][i]*vec->data[0][i];
            }
        } else{
            for(int i=0;i<vec->rows;i++){
                result += vec->data[i][0]*vec->data[i][0];
            }
        }

        return result;
    }

}

struct Matrix *subMat(struct Matrix *mat1, struct Matrix *mat2){
    // Subtracts mat1 - mat2 and returns pointer to resulting matrix

    if(mat1->rows==mat2->rows && mat1->cols==mat2->cols){
        struct Matrix *mat3 = createMatrix(mat1->rows,mat1->cols);
        for(int i=0;i<mat1->rows;i++){
            for(int j=0;j<mat1->cols;j++){
                mat3->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
            }
        }
        return mat3;
    } else{
        printf("Matrix dimensions must match.\n");
        return NULL;
    }
}

struct Matrix *addMat(struct Matrix *mat1, struct Matrix *mat2){
    //Adds matrices mat1 + mat2 together and returns pointer to resulting matrix

    if(mat1->rows==mat2->rows && mat1->cols==mat2->cols){
        struct Matrix *mat3 = createMatrix(mat1->rows,mat1->cols);
        for(int i=0;i<mat1->rows;i++){
            for(int j=0;j<mat1->cols;j++){
                mat3->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
            }
        }
        return mat3;
    } else{
        printf("Matrix dimensions must match.\n");
        return NULL;
    }
}
