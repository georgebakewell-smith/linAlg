#include <stdio.h>
#include <stdlib.h>
#include "linAlg.h"

int main()
{
    double a[] = {1,2,3,4,5}, b[] = {5,4,3,2,1};
    size_t lenArr = sizeof(a) / sizeof(double);

    //add a+b arrays together
    double *arr = addArr(a,b,lenArr);
    printf("%f\n", normSquare(a,lenArr));
    printf("%f", dot(a,a, lenArr));
    //Print the norm square of the result to test
    //printf("\n\n%f", normSquare(arr,lenArr));
    printf("%d", testf());
    freeArray(arr);

    return 0;
}
