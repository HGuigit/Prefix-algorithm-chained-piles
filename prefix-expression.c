/*Guilherme de Souza Pinto da Silva, Estrutura de Dados 1*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX 100

typedef struct pil{
	int vetor[MAX];
	int Ult;
}Pilha;




void insere_topo(Pilha *pil, int x){
	
	if(pil->Ult != MAX){
	pil->Ult += 1;
	pil->vetor[pil->Ult-1] = x;

	}
	else{
		printf("Pilha cheia");
	}

}

int retorna_topo(Pilha *pil){
	return (pil->vetor[pil->Ult-1]);
}


void printa_pilha(Pilha *pil){
	int i;
	for (i=(pil->Ult-1); i>=0; i--){
		
		printf("%d\n", pil->vetor[i]);
	}
}

int pilVaz(Pilha *pil){
	if(pil->Ult == 0){
		return(1);
	}
	else{
		return(0);
	}
}


void retira_topo(Pilha *pil){
	if(pilVaz(pil)){
		printf("Pilha Vazia");
	}
	else{
		pil->Ult -= 1;
	}
}

void esv_pilha(Pilha *pil){
	pil->Ult = 0;
}

int operacao(char simb, int op1, int op2){
	int result;
	switch(simb){
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '$':
			result = pow(op1,op2);
			break;
		
	}
	return(result);	
}
int prefixa(char *exp, int tam){
Pilha *elementos = (Pilha*)malloc(sizeof(Pilha));
elementos->Ult=0;
int ele1;
int ele2;
int result;
int result_final;
int i;
for(i = tam-1; i>=0; i--){
if(exp[i] == '+'){
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao('+',ele1,ele2);
	insere_topo(elementos, result);
	
}
else if(exp[i] == '-'){
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao('-',ele1,ele2);
	insere_topo(elementos, result);
}
else if(exp[i] == '*'){
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao('*',ele1,ele2);
	insere_topo(elementos, result);
	
}
else if(exp[i] == '/'){
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao('/',ele1,ele2);
	insere_topo(elementos, result);
	
}
else if(exp[i] == '$'){
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao('$',ele1,ele2);
	insere_topo(elementos, result);
	

}
else{
	int converte = exp[i] - '0';
	insere_topo(elementos, converte);
}

}

result_final = retorna_topo(elementos);
printf("%d", result_final);

}
int main(){
	
int tam = 9;
//char expressao[9] = "**$*23245";
char expressao[9] = "*3*5+32";

	
prefixa(expressao, tam);	
	
	
	
	
	
	
	
	
return(0);
}