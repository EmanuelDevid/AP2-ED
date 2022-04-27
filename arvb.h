typedef struct arv ArvB;

//Função que cria uma Árvore Binária de Busca Vazia
ArvB* arvb_cria_vazia(void);

//Testa se uma Árvore Binária é vazia.
int arvb_vazia(ArvB *a);

//Função que busca a sub-árvore que contém um inteiro.
ArvB* arvb_busca(ArvB *a,int c);

//Função que imprime os elementos de uma Árvore.
void arvb_imprime(ArvB *a);

//Função que insere um inteiro em uma Árvore.
ArvB* arvb_insere(ArvB *a, int c);

//unção que remove um inteiro em uma Árvore.
ArvB* arvb_remove(ArvB *a, int c);

//Libera o espaço alocado para uma Árvore.
void arvb_libera(ArvB *a);

//função que retorna a altura de uma árvore
int arvb_altura(ArvB *a);

//Questões do trabalho
int folhas_div_n(ArvB* a, int n);

//função que retorna 1 se a árvore for degenerada e 0 caso contrário
int isdegenerada(ArvB* a);

//função que retorna a quantidade de nós com fator de balanceamento iguais a uma parÂmetro n
int nos_fb_n(ArvB* a, int n);

//função que imprime os elementos em comum de duas árvores
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

//função que retorna o número de sub-árvores em relação a origem
int quant_sub_arv(ArvB* a);

//função que retorna o número de nós de uma árvore
int num_nos(ArvB* a);

//função que imprime os elementos por seus respectíveis níveis
void impressao_arv_niveis(ArvB* a);
