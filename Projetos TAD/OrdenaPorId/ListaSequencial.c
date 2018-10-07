#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

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
    if(li == NULL)
        return;
    int i;

	printf("\n%-10s %-15s %-4s\n", "MATRICULA", "NOME", "IDADE");
  	printf("------------------------------------\n");
	for(i=0; i< li->qtd; i++){
        printf("%-10d %-15s %-4d\n", li->dados[i].matricula, li->dados[i].nome, li->dados[i].idade);
	}
}

void ordenar(Lista* li){
    int tam = tamanho_lista(li);
    Lista* temp = cria_lista();
    int fim, i, qtdeTrocas = 0;

	for (fim = tam - 1; fim > 0; fim--) {
		for (i = 0; i < fim; i++) {
			if (li->dados[i].matricula > li->dados[i+1].matricula) {

                int temp_matricula;
                char temp_nome[30];
                int temp_idade;

                temp_matricula = li->dados[i].matricula;
                strcpy(temp_nome, li->dados[i].nome);
                temp_idade = li->dados[i].idade;

				li->dados[i].matricula = li->dados[i+1].matricula;
				strcpy(li->dados[i].nome, li->dados[i+1].nome);
				li->dados[i].idade     = li->dados[i+1].idade;

				li->dados[i+1].matricula = temp_matricula;
				strcpy(li->dados[i+1].nome, temp_nome);
				li->dados[i+1].idade     = temp_idade;

                qtdeTrocas++;
			}
		}
	}
	printf("Ordenado!!!");
}
