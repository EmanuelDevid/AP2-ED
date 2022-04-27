#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"
#include "lista.h"

//Questões dos slides
typedef struct arv{
	int info;
	ArvB *esq;
	ArvB *dir;
}ArvB;

/*struct fila{
	Lista *ini;
	Lista *fim;
};

typedef struct lista {
	int info;
	Lista *prox;
}Lista;*/

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a == NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
			if (a->esq == NULL){
			t = a; a = a->dir;
			free(t);
			}
			else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}
			else{
				t = a->esq;
				while(t->dir!=NULL)
				t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

int arvb_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

//Questões do trabalho
int folhas_div_n(ArvB* a, int n){
	if(arvb_vazia(a)){
		return 0;
	}
	else{
		int contador = 0;
		contador = folhas_div_n(a->esq, n);
		if(a->dir == NULL && a->esq == NULL){
			if(a->info % n == 0){
				return 1;
			}
		}
		contador = contador + folhas_div_n(a->dir, n);
		return contador;
	}
}

int isdegenerada(ArvB* a){
	if(a->esq != NULL && a->dir != NULL){
		return 0;
	}
	if(a->esq == NULL || a->dir == NULL){
		if(a->dir != NULL){
			ArvB* Aux = a;
			Aux = Aux->dir;
			if(Aux->dir == NULL && Aux->esq == NULL){
				return 1;
			}
			return isdegenerada(a->dir);
		}
		else if(a->esq != NULL){
			ArvB* Aux = a;
			Aux = Aux->esq;
			if(Aux->esq == NULL && Aux->dir == NULL){
				return 1;
			}
			return isdegenerada(a->esq);
		}
	}
}

int nos_fb_n(ArvB* a, int n){
	int quant = 0;
	if(arvb_vazia(a)){
		return quant;
	}
	int fb = arvb_altura(a->dir) - arvb_altura(a->esq);
	if(fb == n){
		quant++;
	}
	quant = quant + nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n);
	return quant;
}

/*void elementos_fila(ArvB* a, Fila* f){
	if(!arvb_vazia(a)){
		elementos_fila(a->esq,f);
		fila_insere(f,a->info);
		elementos_fila(a->dir,f);
 	}
}

void impressao_arv_elem_comuns(ArvB* a, ArvB* b){
	//Criando filas
	Fila* fa = fila_cria();
	Fila* fb = fila_cria();
	//Preenchendo as filas com os elementos da árvore
	elementos_fila(a,fa);
	elementos_fila(b,fb);
	//Criando as listas
	Lista* la = lst_cria();
	Lista* lb = lst_cria();
	Lista* l = lst_cria();
	Lista* lAux = lst_cria();
	Lista* lCont = lst_cria();
	//Aolocando os elementos da fila na lista
	la = fa->ini;
	lb = fb->ini;
	//Preenchendo uma lista com os elementos comuns
	lAux = la;
	while(lAux != NULL){
		lCont = lb;
		while(lCont!=NULL){
			if(lAux->info == lCont->info){
				l = lst_insere(l,lAux->info);
			}
			lCont = lCont->prox;
		}
		lAux = lAux->prox;
	}
	
	lst_imprime(l);
}*/

int quant_sub_arv(ArvB* a){//função que retorna o número de sub-árvores em relação a origem
	int n = 0;
	if(!arvb_vazia(a)){
		if(!arvb_vazia(a->dir) || !arvb_vazia(a->esq)){
				n = 1;
		}
		else if(!arvb_vazia(a->dir) && !arvb_vazia(a->esq)){
				n = 2;
		}
	}
	return n;
}

int num_nos(ArvB* a){//função que retorna o número de nós de uma árvore
	int contador = 0;
	if(!arvb_vazia(a)){
		contador = contador + num_nos(a->esq);
		contador = contador + num_nos(a->dir);
	}
	else{
		return 0;
	}
	contador++;
	return contador;
}

void impressao_arv_niveis(ArvB* a){
	int i = 0, f = 1, contnivel = 0, contsa = 0, contaux = 0, contw = 0;
	ArvB* v[num_nos(a)];
	v[0] = a;
	while(f>i){
		contw++;
		if(contw == 2){
			contnivel++;
		}
		a = v[i++];
		printf("%d - nivel %d\n", a->info, contnivel);
		if(a->esq != NULL){
			v[f++] = a->esq;
		}
		if(a->dir != NULL){
			v[f++] = a->dir;
		}
		if(contnivel == 0){
			contsa = quant_sub_arv(a);
		}
		if(contw >= 2 && contsa > 0){
			contaux = contaux + quant_sub_arv(a);
			contsa--;
		}
		if(contw >= 2 && contsa == 0 && contaux!=0){
			contsa = contaux;
			contaux = 0;
			contnivel++; 
		}
	}
}
