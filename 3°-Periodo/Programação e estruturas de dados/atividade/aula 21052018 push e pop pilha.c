/*

pop - apaga

push - adiciona

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Autor: Fernando Kayro
// Data:21/05/2018
// Descri��o: push e pop em uma pilha

typedef struct al{
	
	char nome[20];
	char matricula[6];
	struct al *prox;
}aluno;

aluno *ini, *aux;

void inicio(){
	ini = NULL;
}

int estavazia(){
	
	return (ini==NULL);
}

void push (){
	
	aux = (aluno*) malloc(sizeof(aluno));
	printf ("insira o nome do aluno: ");
	fflush(stdin);
	gets(aux->nome);
	printf ("insira o codigo da matricula: ");
	fflush(stdin);
	gets(aux -> matricula);
	aux->prox = ini;
	ini = aux;
}

void listar (){
	
	for (aux=ini; aux!=NULL; aux = aux->prox){
		
		printf("\nNome: %s \nMatricula: %s \n", aux->nome, aux->matricula);
	}
}

int quantAluno (){
	
	int q = 0;
	
	for (aux = ini; aux!=NULL; aux = aux->prox){
		
		q++;
	}
	
	printf("\nA lista possue %d aluno(s) cadastrados\n", q);
}

void alterar(){
	
	char mat[6];
	listar();
	
	printf("insira a matricula do aluno a ser alterado: ");
	gets(mat);
	
	for (aux=ini; aux!=NULL; aux = aux->prox){
		
		if(!(strcmp(aux->matricula, mat))){
			
			printf("\nNome atual: %s\n", aux->nome);
			printf ("insira o nome do aluno: ");
			fflush(stdin);
			gets(aux->nome);
			printf("\nMatricula atual: %s\n", aux -> matricula);
			printf ("insira o codigo da matricula: ");
			fflush(stdin);
			gets(aux -> matricula);
			break;
		} else{
			printf("\nmatricula nao encontrada!\n");
		}
	}
}

void pop(){
	
//	char mat[6];
//	char *a;
//	a=NULL;
	
//	aluno *ajudante;
	
//	listar();
	
//	printf("insira a matricula do aluno a ser excluido: ");
//	gets(mat);
	
//	for (aux=ini; aux!=NULL; aux = aux->prox){
		
//		if(!(strcmp(aux->matricula, mat))){
			
//			if (!(strcmp(aux, ini))){
//				aux = ini;


//				free(ini);
//				ini = ini->prox;
				
				
				aux = ini;
				ini = aux->prox;
				free(aux);
//			} else{
//				ajudante->prox = aux->prox;
//			}
			
//			break;
//		}
		
//		ajudante = aux;
//	}
}

void propriedade(){
	
	if(estavazia()){
		printf("Lista vazia!");
	}
	else{
		quantAluno();
	}
}

char menu(){
	
	printf("\n\t\t----- M E N U -----");
	printf("\n\t\t1 - Inserir ");
	printf("\n\t\t2 - Exibir ");
	printf("\n\t\t3 - alterar ");
	printf("\n\t\t4 - Excluir ");
	printf("\n\t\t5 - Propriedades ");
	printf("\n\t\t0 - Sair \n");
	fflush(stdin);
	char op = getch();
	system("cls");
	return op;
}

int main (void){
	
	char op;
	
	inicio();
	
	op = menu();
	
	while (op != '0'){
		
		switch (op){
			
			case '1':
				push();
				break;
			case '2':
				listar();
				break;
			case '3':
				alterar();
				break;
			case '4':
				pop();
				break;
			case '5':
				propriedade();
				break;
		}
		op = menu();
	}
}
