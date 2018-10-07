#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int vNumeros[TAM];
unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void insertionSortRecursivo(int *vNumeros, size_t n, size_t i){
    int el , j;

    if(i == n-1){
        return;
    }else{
        insertionSortRecursivo(vNumeros, n, i+1);
        el = vNumeros[i];

        for(j = i+1; j<n; j++){
            if(el > vNumeros[j]){
                vNumeros[j-1] = vNumeros[j];
                vNumeros[j] = el;
            }
            qtdeTrocas++;
        }
    }
}

void gerarNumerosAleatorios() {
	int i;
	//srand( (unsigned)time(NULL) ); // Execute o experimento com esta linha desbilitada
	for (i = 0; i < TAM; i++) {
           vNumeros[i] = rand() % 100;
     }
}


void imprimirNumeros() {
	int i;
	for (i = 0; i < TAM; i++) {
        printf("%d ", vNumeros[i]);
     }
}


int main(int argc, char *argv[]) {
    gerarNumerosAleatorios();
    Ticks[0] = clock();

    insertionSortRecursivo(vNumeros, TAM, 0);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    printf("\n-----------segunda impressao-----------\n");
    imprimirNumeros();

    //printf("\n%d bytes\n", sizeof( unsigned long long ) );

    return 0;
}
