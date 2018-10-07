#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "ListaSequencial.h"

void inserir(Lista* li) {
    char flag;

	do {
		struct aluno a;
		printf("Digite a matricula: ");
		scanf("%d", &a.matricula);

		printf("Digite o nome: ");
		scanf("%s", a.nome);

		printf("Digite a idade: ");
		scanf("%d", &a.idade);

        int incre = tamanho_lista(li);
		a.indice = incre++;

		insere_lista_final(li,a);

		printf("-----------------------------\n");
		printf("Deseja Inserir Outro Registro (S/N)? ");
 	    scanf(" %c", &flag);
	} while(flag != 'N');
}

void menu_de_opcoes(Lista* li) {
	int opcao;

	do {
		printf("\n--------O P C O E S----------\n");
		printf("1 - Inserir\n");
		printf("2 - Listar\n");
		printf("3 - Ordenar\n");
		printf("0 - Sair\n");

		printf("Selecione uma opcao: ");
	 	scanf(" %d", &opcao);

	 	switch(opcao) {
	 		case 1: inserir(li); break;
	 		case 2: imprime_lista(li); break;
			case 3: ordenar(li); break;
	 	}
	} while(opcao != 0);
}

int main(){
    Lista* li = cria_lista();

	menu_de_opcoes(li);

	libera_lista(li);
    system("pause");
    return 0;
}

