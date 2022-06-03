#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLATES 5

struct stack {
   int data;
   struct stack *ptr;
};

typedef struct stack Stack;
typedef Stack *stackPtr;

void push( stackPtr *top, int x ) {
    stackPtr nodePtr;

    nodePtr = malloc(sizeof(Stack));
  
    if(nodePtr != NULL) {
       nodePtr -> data = x;
       nodePtr -> ptr = *top;
       *top = nodePtr;
    }

    else printf("\nERROR !!! (Not enough space)");
}

int pop(stackPtr *top) {
   int pValue;
   stackPtr tempPtr;

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> ptr;
   free(tempPtr);
   return pValue;
}

void printValue(stackPtr showPtr) {
    // pratos -> (1) Vermelho, (2) Verde, (3) Azul, (4) Branco e (5) Laranja
    char *platesArray[NUM_PLATES] = { "Vermelho", "Verde", "Azul", "Branco", "Laranja" };

   if(showPtr == NULL) {
       printf("\nNo value found.");
   }

   else {
     printf("\nNULL ");
      while(showPtr != NULL) {
         printf("<-- (%d) %s ", showPtr -> data +1, platesArray[showPtr -> data]);
         showPtr = showPtr -> ptr;
     }
   }
}

int checkEmpty(stackPtr top) {
   return top == NULL;
}

int main() {
  // passo 1 -> Preencher uma pilha com os cinco pratos citados acima;
  stackPtr stackNewPtr = NULL;

  for (int i = 0; i < 5; ++i) {
    push(&stackNewPtr, i);
  }

  // passo 2 ->  Imprimir a pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top);
  printf("\nResult:\n");
  printValue(stackNewPtr);

  // passo 3 -> Desempilhar todos os elementos, inserindo-os em uma segunda estrutura de datas do tipo pilha.
  stackPtr secondStackPtr = NULL;

  for (int i = NUM_PLATES; i > 0; --i) {
    if (!checkEmpty(stackNewPtr)) {
      int poppedValue = pop(&stackNewPtr);
      push(&secondStackPtr, poppedValue);
    }
  }
  
  // passo 4 -> Imprimir a nova pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top).
  printf("\nNew stack:\n");
  printValue(secondStackPtr);
}

