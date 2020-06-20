#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define MAX 100

typedef struct pil{
	int vetor[MAX];
	int Ult;
}Pilha;
typedef struct pil2{
	char vetor[MAX];
	int Ult;
}Pilha2;



void insere_topo(Pilha *pil, char x){
	
	if(pil->Ult != MAX){
	pil->Ult += 1;
	pil->vetor[pil->Ult-1] = x;

	}
	else{
		printf("Pilha cheia");
	}

}
void insere_topo2(Pilha2 *pil, int x){
	
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
char retorna_topo2(Pilha2 *pil){
	return (pil->vetor[pil->Ult-1]);
}

void printa_pilha(Pilha *pil){
	int i;
	for (i=(pil->Ult-1); i>=0; i--){
		
		printf("%d\n", pil->vetor[i]);
	}
}
void printa_pilha2(Pilha2 *pil){
	int i;
	for (i=(pil->Ult-1); i>=0; i--){
		
		printf("%c\n", pil->vetor[i]);
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
int pilVaz2(Pilha2 *pil){
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
void retira_topo2(Pilha2 *pil){
	if(pilVaz2(pil)){
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
	printf("%d", result);
	system("PAUSE");
	return(result);	
}
int prefixa(char *exp, int tam){
Pilha *elementos = (Pilha*)malloc(sizeof(Pilha));
Pilha2 *operadores = (Pilha*)malloc(sizeof(Pilha));
operadores->Ult=0;
elementos->Ult=0;
int result;
char operador;
char ele1;
char ele2;
int tam_pilha_operadores;
int i;
for(i = 0; i<tam; i++){
if(exp[i] == '+'){
	insere_topo2(operadores, exp[i]);
}
else if(exp[i] == '-'){
	insere_topo2(operadores, exp[i]);
}
else if(exp[i] == '*'){
	insere_topo2(operadores, exp[i]);
}
else if(exp[i] == '/'){
	insere_topo2(operadores, exp[i]);
}
else if(exp[i] == '$'){
	insere_topo2(operadores, exp[i]);

}
else{
	int converte = exp[i] - '0';
	insere_topo(elementos, converte);
}

}

tam_pilha_operadores = operadores->Ult;


for(i=0; i < tam_pilha_operadores; i++){
	operador = retorna_topo2(operadores);
	retira_topo2(operadores);
	ele1 = retorna_topo(elementos);
	retira_topo(elementos);
	ele2 = retorna_topo(elementos);
	retira_topo(elementos);
	result = operacao(operador, ele1, ele2);
	insere_topo(elementos, result);
	

	
}

printa_pilha(elementos);


}
int main(){
	
	
char expressao[9] = "-2/6*3$32";
int tam = 9;
	
prefixa(expressao, tam);	
	
	
	
	
	
	
	
	
return(0);
}


