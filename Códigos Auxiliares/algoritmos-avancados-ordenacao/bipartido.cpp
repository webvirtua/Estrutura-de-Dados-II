#include <stdio.h>
#include <stdlib.h>

#define TAM 16

void imprime_vetor(int* v, int tam) {
	int i, j;
	for (i = 0; i < tam; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int bipartido(int* a, int tam) {
	int c = (tam / 2) - 1, i = 0, j = tam, verifica = 0;

	while (i < c) {
		if (a[i] > a[c])
            verifica += 1;
		i++;
	}
	i++;

	while (i < j) {
		if (a[i] < a[c])
            verifica += 1;
		i++;
	}

	if (verifica == 0){
        printf("\nO vetor É bipartido");
        return c;
	} else {
	    printf("\nO vetor NÃO é bipartido\n");
	}

	return -1;
}

int main(int argc, char *argv[]) {
    int indice;
	//int v[16] = { 33, 22, 55, 33, 44, 22, 99, 66, 55, 11, 88, 77, 33, 88, 66, 66 }; // não é bipartido
	int v[16] = { 11, 22, 25, 33, 04, 22, 29, 36, 55, 56, 88, 77, 83, 88, 66, 66 }; //  bipartido

	imprime_vetor(v, TAM);

	indice = bipartido(v, TAM);
	if (indice >= 0)
        printf("\nA bipartição está caracterizada no indice: %i\n", indice);

	return 0;
}



