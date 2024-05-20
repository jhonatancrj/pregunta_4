#include <stdio.h>
#include <omp.h>

#define N 4

// Función para multiplicar una matriz NxN por un vector de dimensión N
void multiplicarMatrizVector(int matriz[N][N], int vector[N], int resultado[N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += matriz[i][j] * vector[j];
        }
        resultado[i] = suma;
    }
}

int main() {
    int matriz[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int vector[N] = {1, 2, 3, 4};
    int resultado[N] = {0};

    // Multiplicar la matriz por el vector
    multiplicarMatrizVector(matriz, vector, resultado);

    // Mostrar el resultado
    printf("Resultado de la multiplicación de la matriz por el vector:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
