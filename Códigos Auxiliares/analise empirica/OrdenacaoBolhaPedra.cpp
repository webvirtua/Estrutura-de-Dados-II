#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int vNumeros[TAM];
unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void ordenar_bolha_pedra () {
	int fim, i;
	for (fim = TAM-1; fim > 0; fim--) {
		for (i = fim; i > 0; i--) {
			if (vNumeros[i] < vNumeros[i-1]) {
				int temp = vNumeros[i];
				/* troca */
				vNumeros[i] = vNumeros[i-1];
				vNumeros[i-1] = temp;
				qtdeTrocas++;
			}
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

    imprimirNumeros();

    ordenar_bolha_pedra();

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    printf("\n-----------segunda impressao-----------\n");
    imprimirNumeros();

    //printf("\n%d bytes\n", sizeof( unsigned long long ) );

    return 0;
}
