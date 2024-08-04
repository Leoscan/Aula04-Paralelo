/*
*   Processamento Paralelo com Seções
*
*   Implemente um programa que processe duas tarefas independentes em paralelo utilizando a diretiva #pragma omp sections.
*   Uma seção deve calcular a soma dos elementos de um vetor, enquanto a outra seção deve calcular o produto dos elementos
*   de outro vetor. Utilize #pragma omp sections para definir as seções e #pragma omp section para as tarefas individuais.
*/

#include <windows.h>
#include <assert.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[]){
    const int TAM = 5;
    int a[TAM];
    int soma = 0;
    int produto = 1;
    
    srand(time(NULL));

    for (int x = 0; x < TAM; x++) {
        int valor;
        do
        {
            valor = rand() % 10;
        } while (valor == 0);
        

        a[x] = valor;
    }

    #pragma omp parallel 
    {
        #pragma omp sections 
        {
            #pragma omp section
            {
                for (int i = 0; i < TAM; ++i)
                    soma += a[i];
            }
            #pragma omp section 
            {
                for (int i = 0; i < TAM; ++i)
                    produto *= a[i];
            }
        }
    }

    for (int x = 0; x < TAM; x++) {
        printf("a[%d] = %d\n", x, a[x]);
    }
    printf("Soma: %d\nProduto: %d", soma, produto);

}