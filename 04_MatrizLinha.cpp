/*
*   Multiplicação de Matrizes com Divisão de Tarefas
*
*   Implemente um programa para multiplicar duas matrizes quadradas. Use #pragma omp sections para dividir
*   a multiplicação em várias tarefas, onde cada seção será responsável por calcular um subconjunto das
*   linhas da matriz resultante. Utilize a diretiva #pragma omp for dentro de cada seção para paralelizar
*   o cálculo das linhas. Assegure-se de que cada seção lide com um conjunto distinto de linhas da matriz 
*   resultante.
*/

#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]){
    const int ROWS = 2;
    const int COLS = 2;
    int a[ROWS][COLS];
    int b[ROWS][COLS];
    int c[ROWS][COLS];

    #pragma omp parallel 
    {
        #pragma omp single
        {
            srand(time(NULL));
        }

        #pragma omp for collapse(2)
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                a[i][j] = rand() % 10;
                b[i][j] = rand() % 10;
            }
        }
    
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                /* Linha 1 com coluna 1 */
                c[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
                c[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
            }
            #pragma omp section
            {
                /* Linha 2 com coluna 2*/           
                c[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
                c[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
            }
        }
    
    }
    printf("Matriz A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matriz B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    
    printf("Matriz C (Resultado):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}