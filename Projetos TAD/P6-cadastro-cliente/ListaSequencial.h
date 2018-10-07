#define MAX 100
struct aluno{
    int codigo;
    char nome[30];
	char cidade[30];
	char estado[30];
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
void ordenarNome(Lista* li);
void ordenarCodigo(Lista* li);
int deletar(Lista* li);
int PesquisaBinaria(Lista* li);
