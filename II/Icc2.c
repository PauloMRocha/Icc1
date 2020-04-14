#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int num;
  struct list *prox;

}list;

void inserir(list** lista, int x){
  list *novo = NULL;

  if((*lista) == NULL){ //caso 1: seja o primeiro item a ser adicionado na lista
    (*lista) = malloc(sizeof(list));
    (*lista)->num = x;
    (*lista)->prox = NULL;
    return;
  }else{
    if((*lista)->num > x){ //caso 2: o item adicionado tenha que entrar no topo da lista
      novo = malloc(sizeof(list));
      novo->num = x;
      novo->prox = (*lista);
      (*lista)= novo;
      return;
    }
    /*
    caso 3: o item adicionado tenha que entar depois do item passado como argumento
    da função
    */
    if((*lista)->prox == NULL || (*lista)->prox->num > x){
      novo = malloc(sizeof(list));
      novo->num = x;
      novo->prox = (*lista)->prox;
      (*lista)->prox = novo;
      return;
    }else{
      //chamada recursiva, para que a função caminhe na lista
      inserir(&((*lista)->prox), x);
    }
  }
}

void print_list(list *lista){
  list *atual= lista;

  while(atual != NULL){
    printf("%d ", atual->num);
    atual = atual->prox;
  }
  printf("\n");
  return;
}

void clear_list(list *lista){
  list *atual= lista;
  list *aux;

  while(atual != NULL){
    aux = atual->prox;
    free(atual);
    atual = aux;
  }
}

int main(void){
  list *lista=NULL;
  int n, x;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%d", &x);
    inserir(&lista, x);
  }

  print_list(lista);
  clear_list(lista);

  return 0;
}
