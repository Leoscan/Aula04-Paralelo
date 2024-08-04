/*
*   Busca Paralela em Vetor
*
*   Implemente um programa que realize a busca de um valor específico em um vetor de inteiros utilizando
*   #pragma omp for para paralelizar a busca. Além disso, use #pragma omp single para imprimir a posição
*   do valor encontrado na primeira ocorrência, garantindo que apenas uma thread execute a impressão.
*   Utilize uma variável compartilhada para armazenar a posição do valor encontrado e uma cláusula
*   #pragma omp critical para proteger a atualização desta variável.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    const int TAM = 100;
    int a[TAM];
    int valor_procurado = 5;
    int posicao_encontrada = -1;

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        a[i] = rand() % 10;
    }

    #pragma omp parallel shared(posicao_encontrada)
    {
        #pragma omp for
        for (int i = 0; i < TAM; i++) {
            if (a[i] == valor_procurado) {
                #pragma omp critical
                {
                    if (posicao_encontrada == -1) {
                        posicao_encontrada = i;
                    }
                }
            }
        }

        #pragma omp single
        {
            if (posicao_encontrada != -1) {
                printf("Valor %d encontrado na posição %d\n", valor_procurado, posicao_encontrada);
            } else {
                printf("Valor %d não encontrado no vetor\n", valor_procurado);
            }
        }
    }

    return 0;
}
