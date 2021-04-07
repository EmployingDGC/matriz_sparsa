#include "../bool/__init__.c"
#include "../list/__init__.c"
#include <stdlib.h>


typedef struct elementMatrix
{
    int pos;
    struct elementMatrix *next;
    struct elementMatrix *previous;
} EMatrix;



typedef struct matrixSparsa
{
    int len;
    EMatrix *first;
    EMatrix *last;
} Matrix;


