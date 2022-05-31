#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	NODE* next;
}NODE;

typedef struct STACK{
	NODE* top;
} STACK;

STACK *p;

void print(NODE* ptr){
	system("cls");
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void push(){
	NODE* ptr = (NODE *) malloc(sizeof(NODE));
	ptr->data = rand()%100;
	ptr->next = p->top;
	p->top = ptr;
}

int pop(){
	NODE* ptr = p->top;
	int data;
	if(ptr != NULL){
		p->top = ptr->next;
		ptr->next = NULL;
		data = ptr->data;
		free(ptr);
		return data;
	}
}

int main() {
  // passo 1 -> Preencher uma pilha com os cinco pratos citados acima;

  // passo 2 ->  Imprimir a pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top);

  // passo 3 -> Desempilhar todos os elementos, inserindo-os em uma segunda estrutura de datas do tipo pilha.

  // passo 4 -> Imprimir a nova pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top).
}
