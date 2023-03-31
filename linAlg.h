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
struct Matrix *powMatEl(double y, struct Matrix *mat);
struct Matrix *scalarMat(double a, struct Matrix *mat);
struct Matrix *subMat(struct Matrix *mat1, struct Matrix *mat2);
struct Matrix *addMat(struct Matrix *mat1, struct Matrix *mat2);
double normSquare(struct Matrix *vec);
double dot(struct Matrix *vec1, struct Matrix *vec2);
#endif
