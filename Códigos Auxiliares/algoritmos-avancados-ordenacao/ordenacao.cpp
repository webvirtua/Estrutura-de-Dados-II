#include <stdio.h>
#include <stdlib.h>

#define TAM 16

int bipartido(int* a, int p, int r);
void ehHeap(int* v, int n);

void imprime_vetor(int* v, int tam) {
	int i, j;
	for (i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void troca(int* n1, int* n2) {
	int aux;

	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void selectionSort(int* v, int tam) {
	int i, j, min;

	for (i = 0; i < (tam - 1); i++) {
		min = i;

		for (j = (i + 1); j < tam; j++) {
			if (v[j] < v[min])
				min = j;
		}

		if (i != min)
			troca(&v[i], &v[min]);

	}
}

void insertionSort(int* v, int tam) {
	int i, key, j;
	for (i = 1; i < tam; i++)
	{
		key = v[i];
		j = i - 1;

		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

void bubleSort(int* v, int tam) {
	int i, j;

	for (i = 1; i < tam; i++) {

		for (j = 0; j < tam - 1; j++) {

			if (v[j] > v[j + 1])
				troca(&v[j], &v[j + 1]);

		}
	}
}

void bubleSort2(int* v, int tam) {
	int i, j;
	bool houve_troca;

	for (i = 1; i < tam; i++) {

		houve_troca = false;
		for (j = 0; j < tam - 1; j++) {

			if (v[j] > v[j + 1]) {
				troca(&v[j], &v[j + 1]);
				houve_troca = true;
			}

		}
		if (!houve_troca) break;
	}
}
/////////////////////////////////////METODOS SOFISTICADOS////////////////////////////////////////////////////
void shellSort(int* v, int tam) {
	int i, j, h;
	int aux;

	//calcula o h inicial
	for (h = 1; h < tam; h = 3 * h + 1);

	while (h > 0) {
		//atualiza o valor de h
		h = (h - 1) / 3;

		for (i = h; i < tam; i++) {
			aux = v[i];
			j = i;

			//Efetua compara??es entre
			//elementos com dist?ncia h
			while (v[j - h] > aux) {
				v[j] = v[j - h];
				j -= h;
				if (j < h) break;
			}

			v[j] = aux;
		}
	}
}



void quickSort(int *v, int inicio, int fim) {
	int i, j, pivo;

	i = inicio;
	j = fim;
	pivo = v[(inicio + fim) / 2];

	while (i <= j) {
		while (v[i] < pivo && i < fim) i++;

		while (v[j] > pivo && j > inicio) j--;;

		if (i <= j) {
			troca(&v[i], &v[j]);
			i++;
			j--;
		}
	}
	if (j > inicio) {
		printf("%d %d %d\n", inicio, fim, pivo);
		imprime_vetor(v, TAM);
		quickSort(v, inicio, j);
	}
	if (i < fim) {
		printf("%d %d %d\n", inicio, fim, pivo);
		imprime_vetor(v, TAM);
		quickSort(v, i, fim);
	}
}


void merge(int* v, int i1, int j1, int i2, int j2) {
	int temp[TAM];

	int i, j, k;
	i = i1;
	j = i2;
	k = 0;

	while (i <= j1 && j <= j2) {
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	}

	while (i <= j1) {
		temp[k++] = v[i++];
	}

	while (j <= j2) {
		temp[k++] = v[j++];
	}

	for (i = i1, j = 0; i <= j2; i++, j++) {
		v[i] = temp[j];
	}
}

void mergeSort(int* v, int inicio, int fim) {
	if (inicio < fim) {
		int meio = (inicio + fim) / 2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio + 1, fim);
		merge(v, inicio, meio, meio + 1, fim);
	}
}


void refazerHeap(int* v, int i, int n) {
	int esq = 2 * i + 1;
	int dir = 2 * i + 2;

	int maior = i;
	if ((esq <= n) && (v[esq] > v[i])) maior = esq;
	if ((dir <= n) && (v[dir] > v[maior])) maior = dir;

	if (maior != i) {
		troca(&v[i], &v[maior]);
		refazerHeap(v, maior, n);
	}
}

void construirHeap(int* v, int n) {
	int i;
	int metadeTamanho = n / 2;
	for (i = metadeTamanho; i >= 0; i--)
		refazerHeap(v, i, n);
}

void heapSort(int* v, int n) {
	int i, dir;
	construirHeap(v, n);

	dir = n - 1;
	while (dir > 0) {
		troca(&v[0], &v[dir]);
		imprime_vetor(v, TAM);
		dir--;
		refazerHeap(v, 0, dir);
		imprime_vetor(v, TAM);
	}
}

int bipartido(int* a, int p, int r)
{
	int c = a[p], i = p + 1, j = r, t;
	while (i <= j) {
		if (a[i] <= c)
			++i;
		else if (c < a[j])
			--j;
		else {
			troca(&a[i], &a[j]);
			++i;
			--j;
		}
	}
	a[p] = a[j];
	a[j] = c;
	return j;
}

void ehHeap(int* v, int n)
{
	int i;
	bool heap = true;
	for (i = 0; i <= (n - 2) / 2; i++)
	{
		if (v[2 * i + 1] > v[i])
			heap = false;
		if (v[2 * i + 2] > v[i])
			heap = false;
	}
	heap == true ? printf("E um heap\n") : printf("Nao e um heap\n");
}


int main(int argc, char *argv[]) {

	//int v[16] = { 33, 22, 55, 33, 44, 22, 99, 66, 55, 11, 88, 77, 33, 88, 66 , 66 };
	int v[16] = { 33, 22, 55, 33, 44, 22, 99, 66, 55, 11, 88, 77, 33, 88, 66, 66 };

	//imprime_vetor(v, TAM);
	//selectionSort(v, TAM);
	//insertionSort(v, TAM);
	//bubleSort(v, TAM);
	//bubleSort2(v, TAM);
	//shellSort(v, TAM);
	quickSort(v, 0, TAM - 1);
	//refazerHeap(v, 0, TAM - 1);
	//mergeSort(v, 0, TAM-1);
	//heapSort(v, TAM);
	//ehHeap(v, TAM);
	imprime_vetor(v, TAM);

	system("pause");
	return 0;
}



