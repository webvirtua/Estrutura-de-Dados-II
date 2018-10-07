#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000

int vNumeros[TAM];
unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];

void ordenar_quick(int inicio, int fim){
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vNumeros[meio];

   do{
      while (vNumeros[i] < pivo) i = i + 1;
      while (vNumeros[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vNumeros[i];
         vNumeros[i] = vNumeros[j];
         vNumeros[j] = aux;
         i = i + 1;
         j = j - 1;
         qtdeTrocas++;
      }
   }while(j > i);

   if(inicio < j) ordenar_quick(inicio, j);
   if(i < fim) ordenar_quick(i, fim);
}

void ordenar_bolha () {
	int fim,i;
	for (fim=TAM-1; fim>0; fim--) {
		for (i=0; i<fim; i++) {
			if (vNumeros[i]>vNumeros[i+1]) {
				int temp = vNumeros[i];
				/* troca */
				vNumeros[i] = vNumeros[i+1];
				vNumeros[i+1] = temp;
				qtdeTrocas++;
			}
		}
	}
}

void insertionSort() {
    int i, c, d, t;

    for (c = 1 ; c <= TAM - 1; c++) {
    d = c;

        while ( d > 0 && vNumeros[d-1] > vNumeros[d]) {
          t = vNumeros[d];
          vNumeros[d] = vNumeros[d-1];
          vNumeros[d-1] = t;
          d--;
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

    //imprimirNumeros();

    ordenar_bolha();
    //ordenar_quick(0, TAM-1);
    //insertionSort();

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    //printf("\n-----------segunda impressao-----------\n");
    //imprimirNumeros();

    //printf("\n%d bytes\n", sizeof( unsigned long long ) );



    return 0;
}
/*
void insertionSort(int ar[], int tamanho) {
    int i, c, d, t;

    for (c = 0; c < tamanho; c++) {
    scanf("%d", &ar[c]);
    }

    for (c = 1 ; c <= tamanho - 1; c++) {
    d = c;

        while ( d > 0 && ar[d-1] > ar[d]) {
          t          = ar[d];
          ar[d]   = ar[d-1];
          ar[d-1] = t;

          d--;
        }
    }

    printf("Ordenando:\n");

    for (c = 0; c <= tamanho - 1; c++) {
    printf("%d\n", ar[c]);
    }
}
*/
