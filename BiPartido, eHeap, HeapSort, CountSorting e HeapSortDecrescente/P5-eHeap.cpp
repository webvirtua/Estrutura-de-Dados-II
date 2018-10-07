#include <stdio.h>
#include <stdlib.h>

#define TAM 15

void imprime_vetor(int* v, int tam) {
	int i, j;
	for (i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

bool eHeap(int* v, int n) {
	for (int i = 0; i <= (n - 2) / 2; i++) {
		if (v[2 * i + 1] > v[i])
			return false;
		if (v[2 * i + 2] > v[i])
			return false;
	}

	return true;
}


int main(int argc, char *argv[]) {

	int v[15] = { 16, 11, 15, 9, 10, 13, 14, 8, 2, 1, 5, 12, 6, 3, 7 }; // é um heap
	//int v[15] = { 33, 22, 55, 33, 44, 22, 99, 66, 55, 11, 88, 77, 33, 88, 66 }; // nao é um heap

	imprime_vetor(v, TAM);

	if (eHeap(v, TAM)){
        printf("\nÉ um heap\n");
	} else {
        printf("\nNAO e um heap\n");
	}

	return 0;
}



