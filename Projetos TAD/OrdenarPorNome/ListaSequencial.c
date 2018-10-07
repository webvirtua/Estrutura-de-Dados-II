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
    int temp_matricula;
    char temp_nome[30];
    int temp_idade;
    int i, j, mini, verifica, qtdeTrocas = 0;

    for (i = 0; i < (tam-1); i++) {
        mini = i;

        for (j = (i+1); j < tam; j++) {
            verifica = strcmp(li->dados[j].nome, li->dados[mini].nome); // primeira maior -> lu - ju = 2 // primeira menor-> ju - lu = -2 // se for igual é zero

            if(verifica < 0)
                mini = j;
        }

        if (li->dados[i].matricula != li->dados[mini].matricula) {
            temp_matricula = li->dados[i].matricula;
            strcpy(temp_nome, li->dados[i].nome);
            temp_idade = li->dados[i].idade;

            li->dados[i].matricula = li->dados[mini].matricula;
            strcpy(li->dados[i].nome, li->dados[mini].nome);
            li->dados[i].idade = li->dados[mini].idade;

            li->dados[mini].matricula = temp_matricula;
            strcpy(li->dados[mini].nome, temp_nome);
            li->dados[mini].idade = temp_idade;
            qtdeTrocas++;
        }
    }
	printf("Ordenado!!!\n");
	printf("Quantidade de trocas: %i", qtdeTrocas);
}
