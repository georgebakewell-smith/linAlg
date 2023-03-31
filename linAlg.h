#ifndef linAlg
#define linAlg

struct Matrix {
    int rows;
    int cols;
    double **data;
};

struct Matrix *multMat(struct Matrix *mat1, struct Matrix *mat2);
void printMat(struct Matrix *mat);
struct Matrix *createMatrix(size_t m, size_t n);
void freeMatrix(struct Matrix *mat);
void setMatrix(struct Matrix *mat, const int i, const int j, double x);
double *powArrEl(double y, const double array[], size_t lenArr);
double *vecScalar(double a, const double array[], size_t lenArr);
void freeArray(double array[]);
double *addArr(const double array1[], const double array2[], size_t lenArr);
double *subArr(const double array1[], const double array2[], size_t lenArr);
double normSquare(struct Matrix *vec);
void printArr(double array[], size_t lenArr);
double dot(double array1[], double array2[], size_t lenArr);
#endif
