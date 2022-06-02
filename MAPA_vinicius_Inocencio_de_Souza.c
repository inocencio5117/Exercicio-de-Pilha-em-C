#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLATES 5

struct stack
{
   int data;
   struct stack *ptr; //pointer type of stack
};

typedef struct stack Stack;
typedef Stack *stackPtr;

void push( stackPtr *top, int x ) {
    stackPtr nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(Stack));

    //pushing value at the top of stack only if there is space
    if(nodePtr != NULL) {
       nodePtr -> data = x;
       nodePtr -> ptr = *top;
       *top = nodePtr;
    }

    else
       printf("\nERROR !!! (Not enough space)");
}

int pop(stackPtr *top)
{
   int pValue; //variable for value at the top
   stackPtr tempPtr; //temporary pointer

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> ptr;
   free(tempPtr); //free temporary pointer value
   return pValue;
}

void printValue(stackPtr showPtr) {
   if(showPtr == NULL) {
       printf("\nNo value found.");
   }
   else {
      printf("\nData stored in stack:\n");

      while(showPtr != NULL) {
         printf("%d --> ", showPtr -> data);
         showPtr = showPtr -> ptr;
     }
     printf("NULL\n");
   }
}

int checkEmpty(stackPtr top)
{
   return top == NULL;
}

// pratos -> (1) Vermelho, (2) Verde, (3) Azul, (4) Branco e (5) Laranja
char *arr3[NUM_PLATES] = { "Vermelho",
                            "Verde",
                            "Azul",
                            "Branco",
                            "Laranja" };

int main() {
  // passo 1 -> Preencher uma pilha com os cinco pratos citados acima;
  stackPtr stackNewPtr = NULL;

  for (int i = 0; i < 5; ++i) {
    push(&stackNewPtr, i);
  }

  // passo 2 ->  Imprimir a pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top);
  printValue(stackNewPtr);

  // passo 3 -> Desempilhar todos os elementos, inserindo-os em uma segunda estrutura de datas do tipo pilha.
  stackPtr secondStackPtr = NULL;

  for (int i = NUM_PLATES; i > 0; --i) {
    if (!checkEmpty(stackNewPtr)) {
      int popedValue = pop(&stackNewPtr);
      printf("\nPopped Value: %d\n", popedValue);
      push(&secondStackPtr, popedValue);
    }
  }
  
  // passo 4 -> Imprimir a nova pilha na ordem em que os elementos foram inseridos (iniciando pela base, e finalizando pelo top).

  printf("\nNew stack:\n");
  printValue(secondStackPtr);
}
