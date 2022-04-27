#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "lista.h"

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	f->fim = l;
}

void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}
