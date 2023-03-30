#ifndef linAlg
#define linAlg

double *vecScalar(double a, const double array[], size_t lenArr);
int testf();
void freeArray(double array[]);
double *addArr(const double array1[], const double array2[], size_t lenArr);
double *subArr(const double array1[], const double array2[], size_t lenArr);
double normSquare(const double array[], size_t lenArr);
void printArr(double array[], size_t lenArr);
double dot(double array1[], double array2[], size_t lenArr);
#endif
