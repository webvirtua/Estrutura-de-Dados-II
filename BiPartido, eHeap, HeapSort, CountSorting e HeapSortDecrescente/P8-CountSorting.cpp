#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int vNumeros[TAM];
unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void selection_sort() {
  int i, j, mini, aux;

  for (i = 0; i < (TAM-1); i++) {
     mini = i;
     for (j = (i+1); j < TAM; j++) {
       if(vNumeros[j] < vNumeros[mini])
         mini = j;
     }
     if (vNumeros[i] != vNumeros[mini]) {
       aux = vNumeros[i];
       vNumeros[i] = vNumeros[mini];
       vNumeros[mini] = aux;
       qtdeTrocas++;
     }
  }
}

void gerarNumerosAleatorios() {
	for (int i = 0; i < TAM; i++) {
           vNumeros[i] = rand() % 100;
     }
}

void imprimirNumeros() {
	int i;
	for (i = 0; i < TAM; i++) {
        printf("%d ", vNumeros[i]);
     }
}

void coutingSort(int* a, int m) {
	int n = m, i, sum = 0, vetorAuxiliar[TAM], vetorOrdenado[TAM];

	for (i = 0; i < m; i++)
        vetorAuxiliar[i] = 0;
	for (i = 0; i < n; i++)
        vetorAuxiliar[a[i]]++;

	for (i = 1; i < m; i++) {
		int dum = vetorAuxiliar[i];
		vetorAuxiliar[i] = sum;
		sum += dum;
		qtdeTrocas++;
	}

	for (i = 0; i < n; i++) {
		vetorOrdenado[vetorAuxiliar[a[i]]] = a[i];
		vetorAuxiliar[a[i]]++;
	}

	for (i = 0; i < n; i++)
        a[i] = vetorOrdenado[i];
}

int main(int argc, char *argv[]) {
    gerarNumerosAleatorios();
    Ticks[0] = clock();

    imprimirNumeros();
    coutingSort(vNumeros, TAM);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    printf("\n-----------segunda impressao-----------\n");
    imprimirNumeros();

    return 0;
}
