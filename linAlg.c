
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linAlg.h"

void printMat(struct Matrix *mat){

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

double *vecScalar(double a, const double array[], size_t lenArr){
    //Takes in scalar and array and returns the array multiplied by the scalar
    double *result = (double*)malloc(lenArr*sizeof(double));
    for(int i=0;i<lenArr;i++){
        result[i] = a*array[i];
    }
    return result;
}

void freeArray(double array[]){
    //Frees array from within library
    free(array);
    printf("\nFree successful!");
}

double dot(double array1[], double array2[], size_t lenArr){
//Takes in two arrays and returns the dot product
double result = 0;

for(int i=0;i<lenArr;i++){
   result += array1[i]*array2[i];
}
return result;

}

void printArr(double *array, size_t lenArr){
    //Takes in an array and prints it as a column vector
    for(int i=0;i<lenArr;i++){
        printf("%f\n", array[i]);
    }
}

double *powArrEl(double y, const double array[], size_t lenArr){
    //Calculates element wise exponentiation of array^y
    double *result = (double*)malloc(lenArr*sizeof(double));
    for(int i=0;i<lenArr;i++){
        result[i] = pow(array[i],y);
    }

    return result;
}

double normSquare(const double array[], size_t lenArr){
    //Calculates norm square of an array and returns as scalar
    double result = 0;

    for(int i=0;i<lenArr;i++){
        result += array[i]*array[i];
    }
    return result;
}

double *subArr(const double array1[], const double array2[], size_t lenArr){
    //Perfoms a - b on arrays a,b and returns point to resulting array
    double *sumArr = (double*)malloc(lenArr*sizeof(double));

    for(int i=0;i<lenArr;i++){
        sumArr[i] = array1[i] - array2[i];
    }

    return sumArr;
}

double *addArr(const double array1[], const double array2[], size_t lenArr){
    //Adds arrays a + b together and returns point to resulting array
    double *sumArr = (double*)malloc(lenArr*sizeof(double));

    for(int i=0;i<lenArr;i++){
        sumArr[i] = array1[i] + array2[i];
    }

    return sumArr;
}
