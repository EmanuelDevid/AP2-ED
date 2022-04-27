typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);
