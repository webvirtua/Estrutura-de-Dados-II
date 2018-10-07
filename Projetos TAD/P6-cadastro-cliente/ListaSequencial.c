#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};
int binario = 0;

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL || li->qtd == 0) {
        printf("\nA LISTA ESTA VAZIA:\n");
        return;
    }
    int i;

	printf("\n%-10s %-15s %-15s %-15s\n", "CODIGO", "NOME", "CIDADE", "ESTADO");
  	printf("------------------------------------\n");
	for(i=0; i< li->qtd; i++){
        printf("%-10d %-15s %-15s %-15s\n", li->dados[i].codigo, li->dados[i].nome, li->dados[i].cidade, li->dados[i].estado);
	}
}

void ordenar(Lista* li){
    int tipo;
    printf("TIPO DE ORDENACAO!!!\n 1 - Ordenar por Nome\n 2 - Ordenar nor Codigo\n Selecione uma opcao: ");
    scanf("%d", &tipo);

    if (tipo == 1) {
        ordenarNome(li);
    } else if (tipo == 2){
        ordenarCodigo(li);
    } else {
        printf("O VETOR NAO FOI ORDENADO!");
    }
}

void ordenarNome(Lista* li){
    int tam = tamanho_lista(li);
    Lista* temp = cria_lista();

    int i, j, mini, verifica, qtdeTrocas = 0;

    for (i = 0; i < (tam-1); i++) {
        mini = i;

        for (j = (i+1); j < tam; j++) {
            verifica = strcmp(li->dados[j].nome, li->dados[mini].nome); // primeira maior -> lu - ju = 2 // primeira menor-> ju - lu = -2 // se for igual é zero

            if(verifica < 0)
                mini = j;
        }

        if (li->dados[i].codigo != li->dados[mini].codigo) {
            temp->dados[1] = li->dados[i];
            li->dados[i] = li->dados[mini];
            li->dados[mini] = temp->dados[1];

            qtdeTrocas++;
        }
    }
	printf("\nVETOR ORDENADO POR NOME!!!\n");
	binario = 0;
	printf("Quantidade de trocas: %i", qtdeTrocas);
}

void ordenarCodigo(Lista* li){
    int tam = tamanho_lista(li);
    Lista* temp = cria_lista();
    int fim, i, qtdeTrocas = 0;

	for (fim = tam - 1; fim > 0; fim--) {
		for (i = 0; i < fim; i++) {
			if (li->dados[i].codigo > li->dados[i+1].codigo) {

                temp->dados[1] = li->dados[i];
                li->dados[i] = li->dados[i+1];
                li->dados[i+1] = temp->dados[1];

                qtdeTrocas++;
			}
		}
	}
	printf("\nVETOR ORDENADO PELO CODIGO!!!\n");
	binario = 1;
	printf("Quantidade de trocas: %i", qtdeTrocas);
}

int deletar(Lista* li){
    if(li == NULL || li->qtd == 0 || lista_vazia(li)) {
        printf("\nA LISTA ESTA VAZIA:\n");
        return 0;
    }

    int i = 0, j, mat;

    printf("DELETAR CLIENTE:\n");
    printf("Digite o numero do Codigo:");
    scanf("%d", &mat);

    while (i < li->qtd && li->dados[i].codigo != mat)
        i++;

    if (i == li->qtd) {
        printf("\nCLIENTE NAO FOI ENCONTRADO!\n");
        return 0;
    }

    for (j = i; j < li->qtd-1; j++) {
        li->dados[j] = li->dados[j+1];
    }
    li->qtd--;

    if (mat == li->dados[i].codigo) {
        printf("CLIENTE: %d DELETADO\n", li->dados[i].codigo, li->dados[i].nome, li->dados[i].cidade, li->dados[i].estado);
    } else {
        printf("\nCLIENTE NAO FOI ENCONTRADO:\n");
    }
    return 1;
}

int PesquisaBinaria(Lista* li) {
	int i, x, Esq, Dir;

	if (lista_vazia(li) || li->qtd == 0) {
        printf("A LISTA ESTA VAZIA:\n");
        return 0;
    }

	printf("BUSCAR CLIENTE:\n");
    printf("Digite o Codigo:");
    scanf("%d", &x);

    if (binario != 1) {
        ordenarCodigo(li);
    }

	if (li->qtd == 0)
		return 0;
	else {
		Esq = 0;
		Dir = li->qtd;
		do {
			i = (Esq + Dir ) / 2;

			if (x > li->dados[i].codigo)
				Esq = i + 1;
			else Dir = i - 1;

		} while (x != li->dados[i].codigo && Esq <= Dir );

		if (x == li->dados[i].codigo) {
            printf("\nCLIENTE ENCONTRADO:\n");
            printf("%-10d %-15s %-15s %-15s\n", li->dados[i].codigo, li->dados[i].nome, li->dados[i].cidade, li->dados[i].estado);
			return i ;
		} else {
		    printf("\nCLIENTE NAO FOI ENCONTRADO:\n");
			return 0;
		}
	}
}
