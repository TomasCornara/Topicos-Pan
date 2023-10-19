#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

int main() {
    int col = 3;  // Tamaño de las matrices (cambiar según sea necesario)

    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mat2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int matResult[3][3]={0};

    productoMatricial(col, mat1, mat2, matResult);

    printf("Matriz resultante:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matResult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
