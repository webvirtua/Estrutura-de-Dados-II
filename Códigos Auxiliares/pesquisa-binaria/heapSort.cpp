#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void imprimirNumeros(int* v) {
	int i;
	for (i = 0; i < TAM; i++) {
        printf("%d ", v[i]);
     }
}

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
             qtdeTrocas++;
          } else {
             break;
          }
      }
      a[pai] = t;
      imprimirNumeros(a);
      printf("\n");
   }
}

int main(int argc, char *argv[]) {
    Ticks[0] = clock();

    int v[13] = { 17, 12, 8, 5, 3, 6, 2, 4, 2, 1 };

    heapsort(v, TAM);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    return 0;
}
