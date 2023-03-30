#include <stdio.h>
#include <stdlib.h>
#include "linAlg.h"

int main()
{
    double a[] = {1,2,3,4,5}, b[] = {5,4,3,2,1};
    size_t lenArr = sizeof(a) / sizeof(double);

    //add a+b arrays together
    double *arr = addArr(a,b,lenArr);
    double *arr2 = vecScalar(3,arr,lenArr);
    printArr(arr,lenArr);
    printArr(arr2, lenArr);

    freeArray(arr);
    freeArray(arr2);

    return 0;
}
