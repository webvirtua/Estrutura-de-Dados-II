#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 13

unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void imprimirNumeros(int* v) {
	int i;
	for (i = 0; i < TAM; i++) {
        printf("%d ", v[i]);
     }
}

void heapify(int a[], int tam, int i) {
    int temp, t = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < tam && a[l] < a[t])
        t = l;

    if (r < tam && a[r] < a[t])
        t = r;

    if (t != i) {
        temp = a[i];
        a[i] = a[t];
        a[t] = temp;
        qtdeTrocas++;

        heapify(a, tam, t);
    }
}

void heapSort(int a[], int tam) {
    int temp;

    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(a, tam, i);

    for (int i = tam - 1; i >= 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        qtdeTrocas++;

        heapify(a, i, 0);
    }
}

int main(){
    Ticks[0] = clock();
    int a[] = { 16, 15, 144, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4 };

    heapSort(a, TAM);

    imprimirNumeros(a);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);
}
