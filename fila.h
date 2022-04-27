typedef struct lista Lista;
typedef struct fila Fila;

//Função que cria uma Fila.
Fila* fila_cria(void);

//Testa se uma Fila é vazia.
int fila_vazia(Fila *f)

//Função que adiciona um elemento em uma Fila.
void fila_insere(Fila *f, int info);

//Função que imprime os elementos de uma Fila.
void fila_imprime(Fila *f);
