/*
*   Cálculo Paralelo da Soma de um Vetor
*
*   Implemente um programa que calcule a soma dos elementos de um vetor de inteiros utilizando a diretiva #pragma omp for. 
*   Divida o trabalho entre múltiplas threads para somar partes do vetor em paralelo e combine os resultados parciais
*   em uma única soma total. Utilize a redução (reduction) com a diretiva #pragma omp for para acumular a soma de forma segura.
*/

#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h> 
#include <time.h>

int main(int argc, char *argv[]){
    const int TAM = 100;
    int a[TAM], b[TAM];
    int total = 0;
    
    srand(time(NULL));

    for (int x = 0; x < TAM; x++) {
        a[x] = rand() % 100;
        b[x] = rand() % 100;
    }

    #pragma omp parallel for reduction(+:total)
    for (int x = 0; x < TAM; x++) {
        total += a[x] + b[x];
    }

    printf("Soma total dos elementos do vetor: %d\n", total);
    return 0;
}