/* 
*   Inicialização de Matriz com Tarefa Única
*
*   Implemente um programa que inicialize uma matriz 2D de inteiros com valores aleatórios. 
*   Use a diretiva #pragma omp single para garantir que apenas uma thread execute a função 
*   de inicialização do gerador de números aleatórios antes de preencher a matriz em paralelo
*   com #pragma omp for. Certifique-se de que a função de inicialização do gerador de números
*   aleatórios seja executada apenas uma vez.
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

    #pragma omp parallel 
    {
        #pragma omp single
        {
            srand(time(NULL));
        }

        #pragma omp for 
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                a[i][j] = rand() % 100;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}