#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct pilha{
    int valor;
    int ult;
    struct pilha *prox;
}Pilha;

Pilha *inicia_pilha(Pilha *p) {
	p = (Pilha *)malloc(sizeof(Pilha));
	p->prox = NULL;
	p->ult = -1;
	return(p);
}

int pilvaz(Pilha *p){
	 
    if(p->ult == -1){

        return(1);
    }
    else{
        
        return(0);
       
    }
   
}
//push 
void insereTopo(Pilha *p, int x){
	Pilha *aux;
	int flag;
	if(pilvaz(p)){
		aux = (Pilha *)malloc(sizeof(Pilha));
		p->prox = aux;
		aux->valor = x;
		aux->prox = NULL;	
	}
	else{
	for(aux = p->prox; flag != 1; aux = aux->prox){
		if(aux->prox == NULL){
			aux->prox = (Pilha *)malloc(sizeof(Pilha));
			aux->prox->valor = x;
			aux->prox->prox = NULL;
			flag = 1;
		}
		
	}
	
	}
	p->ult += 1;	
}

void printaPilha(Pilha *p){
	printf("\n---------------------------\n");
	Pilha *aux;
	aux = p->prox;
	if(aux == NULL){
		printf("Pilha Vazia");
	}
	for(aux = p->prox; aux != NULL; aux = aux->prox){
		printf("%d\n", aux->valor);
	}
	
	printf("\n---------------------------\n");
	
	
}

int retornaTopo(Pilha *p){
	Pilha *aux;
	for(aux = p->prox; aux != NULL; aux = aux->prox){
		if(aux->prox == NULL){
			return(aux->valor);
		}
	}
}
void retiraTopo(Pilha *p){
	Pilha *aux;
	Pilha *aux2;
	int flag;
	aux2 = p;


	for(aux = p->prox; flag!=1; aux = aux->prox){
		if(aux == NULL){
			flag=1;
		}
		else if(aux->prox == NULL){
			Pilha *remove = aux;
			aux2->prox = NULL;
			free(remove);
			flag = 1;
		}
		else{
		aux2 = aux2->prox;
		}
	}
	if(p->ult != -1){
	p->ult -= 1;
}
}

void esvPilha(Pilha *p){
	p->ult = -1;
	if(p->prox == NULL){
		printf("Pilha ja vazia!");
	}
	else{
	while(p->prox != NULL){
		retiraTopo(p);
		
		
	}
}
	
}

int main(){

Pilha *p;
int x;

p = inicia_pilha(p);

scanf("%d", &x);
insereTopo(p,x);
scanf("%d", &x);
insereTopo(p,x);
scanf("%d", &x);
insereTopo(p,x);

printaPilha(p);





return(0);
}



