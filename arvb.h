typedef struct arv ArvB;

//Fun��o que cria uma �rvore Bin�ria de Busca Vazia
ArvB* arvb_cria_vazia(void);

//Testa se uma �rvore Bin�ria � vazia.
int arvb_vazia(ArvB *a);

//Fun��o que busca a sub-�rvore que cont�m um inteiro.
ArvB* arvb_busca(ArvB *a,int c);

//Fun��o que imprime os elementos de uma �rvore.
void arvb_imprime(ArvB *a);

//Fun��o que insere um inteiro em uma �rvore.
ArvB* arvb_insere(ArvB *a, int c);

//un��o que remove um inteiro em uma �rvore.
ArvB* arvb_remove(ArvB *a, int c);

//Libera o espa�o alocado para uma �rvore.
void arvb_libera(ArvB *a);

//fun��o que retorna a altura de uma �rvore
int arvb_altura(ArvB *a);

//Quest�es do trabalho
int folhas_div_n(ArvB* a, int n);

//fun��o que retorna 1 se a �rvore for degenerada e 0 caso contr�rio
int isdegenerada(ArvB* a);

//fun��o que retorna a quantidade de n�s com fator de balanceamento iguais a uma par�metro n
int nos_fb_n(ArvB* a, int n);

//fun��o que imprime os elementos em comum de duas �rvores
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

//fun��o que retorna o n�mero de sub-�rvores em rela��o a origem
int quant_sub_arv(ArvB* a);

//fun��o que retorna o n�mero de n�s de uma �rvore
int num_nos(ArvB* a);

//fun��o que imprime os elementos por seus respect�veis n�veis
void impressao_arv_niveis(ArvB* a);
