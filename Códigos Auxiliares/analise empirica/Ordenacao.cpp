#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 11

int vNumeros[TAM];
unsigned long long qtdeTrocas = 0;
clock_t Ticks[2];
int vetor[TAM] = {8, 10, 3, 2, 9, 4, 1, 5, 7, 11, 6};

void ordenar_quick(int inicio, int fim){
   int pivo, aux, i, j, meio;
   i = inicio;
   j = fim;
   //printf("\ninicio: %d | fim: %d", inicio, fim);

   meio = (int) ((i + j) / 2);
   pivo = vetor[fim];
   //printf("\npivo: %d, ii=%d", pivo, i);

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         //printf("\nvNumeros[i]: %d | vetor[j]: %d, ii=%d, jj=%d", vetor[i], vetor[j], i, j);
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
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
	int i;
	//srand( (unsigned)time(NULL) ); // Execute o experimento com esta linha desbilitada
	for (i = 0; i < TAM; i++) {
           vNumeros[i] = rand() % 100;
     }
}


void imprimirNumeros() {
	int i;
	for (i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
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

    //ordenar_bolha();
    ordenar_quick(0, TAM-1);
    //insertionSort();
    //insertionSortRecursivo(vNumeros, TAM, 0);
    //selection_sort();
    //coutingSort(vNumeros, TAM);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nQtde de Trocas: %llu \n", qtdeTrocas);
    printf("Tempo gasto: %g ms.\n", Tempo);

    printf("\n-----------segunda impressao-----------\n");
    imprimirNumeros();

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
