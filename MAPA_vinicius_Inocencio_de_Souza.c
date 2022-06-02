#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE{
	int data;
	struct NODE* next;
} NODE;

typedef struct _STACK{
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

void push(int element){
	NODE* ptr = (NODE*) malloc(sizeof(NODE));
	ptr->data = element;
	ptr->next = p->top->next;
	p->top = ptr;
}

// int pop(){
// 	NODE* ptr = p->top;
// 	int data;
// 	if(ptr != NULL){
// 		p->top = ptr->next;
// 		ptr->next = NULL;
// 		data = ptr->data;
// 		free(ptr);
// 		return data;
// 	}
// }

#define PLATES_NUMB 5
// pratos -> (1) Vermelho, (2) Verde, (3) Azul, (4) Branco e (5) Laranja
char *plates[PLATES_NUMB] = {"Vermelho", "Verde", "Azul", "Branco", "Laranja"};

int main() {
  // passo 1 -> Preencher uma pilha com os cinco pratos citados acima;
  // for (int i = 0; i < PLATES_NUMB; ++i) {
  //   printf("%s\n", plates[i]);
  //   push(i);
  // }

  push(1);
  print(p);

  // passo 2 ->  Imprimir a pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top);

  // passo 3 -> Desempilhar todos os elementos, inserindo-os em uma segunda estrutura de datas do tipo pilha.

  // passo 4 -> Imprimir a nova pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top).
}
