
#include <stdio.h>
#include <stdlib.h>
#include "linAlg.h"

int testf(){
    int a=2;
    return a;
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

void printArr(double array[], size_t lenArr){
    //Takes in an array and prints it as a column vector
    for(int i=0;i<lenArr;i++){
        printf("%f\n", array[i]);
    }
}

double normSquare(const double array[], size_t lenArr){
    //Calculates norm square of an array and returns as scalar
    double result = 0;

    for(int i=0;i<lenArr;i++){
        result += array[i]*array[i];
    }
    return result;
}

double *addArr(const double array1[], const double array2[], size_t lenArr){
    //Adds arrays a + b together and returns point to resulting array
    double *sumArr = (double*)malloc(lenArr*sizeof(double));

    for(int i=0;i<lenArr;i++){
        sumArr[i] = array1[i] + array2[i];
    }

    return sumArr;
}
