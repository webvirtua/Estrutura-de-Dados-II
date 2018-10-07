#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
	int idade;
	int indice;
};

typedef struct lista Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void ordenar(Lista* li);
