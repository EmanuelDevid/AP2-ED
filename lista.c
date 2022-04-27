#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista {
	int info;
	Lista *prox;
}Lista;

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void lst_libera(Lista *l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}
