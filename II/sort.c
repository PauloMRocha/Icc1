#include <stdio.h>
#include <stdlib.h>

void bb_sort(int* vetor, int n){
  int aux;
  for(int j=0; j<n; j++){
    for(int i=n-1; i>0; i--){
      if(vetor[i]<vetor[i-1]){
        aux = vetor[i];
        vetor[i] = vetor[i-1];
        vetor[i-1] = aux;
      }
    }
  }
  return;
}

void quick_sort(int vetor[],int esq,int dir){
	//printf("%d %d",esq, dir);
	int pivo = vetor[(esq+dir)/2],aux;
	int i=esq,j=dir;
	do{
		while(vetor[i]>pivo)
			i++;
		while(vetor[j]<pivo)
			j--;
		if(i<j){
			aux=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=aux;
		}
	}while(i<j);
	if(esq < j-1)
		quick_sort(vetor,esq,j-1);
	if(i+1 <dir)
		quick_sort(vetor,i+1,dir);
}

void quick(int* vet, int e, int d){
  int piv =vet[(e+d)/2];
  int i=e, j=d, aux, flag=0;
  do{
    while(vet[i]<=piv) i++;
    while(vet[j]>piv) j--;
    if(i<j){
      aux = vet[i];
      vet[i] = vet[j];
      vet[j] = aux;
    }
  }while(i<j);
  if(e<j-1) quick(vet, e, j-1);
  if(d>i+1) quick(vet, i+1, d);
  return;
}

int maximo(int v[], int ini, int fim){
  if(ini==fim) return v[ini];
  int a=0, b=0;
  int meio = (ini+fim)/2;

  a = maximo(v, ini, meio);
  b = maximo(v, meio+1, fim);
  if(a > b)return a;
  else return b;
}

int main(void){
  int* vet;
  int n;

  scanf("%d", &n);

  vet = malloc(sizeof(int)*n);

  for(int i=0; i<n; i++){
    scanf("%d", &vet[i]);
  }
  for(int i=0; i<n; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");
  printf("%d\n", maximo(vet, 0, n-1));
  //bb_sort(vet, n);
  quick_sort(vet, 0, n-1);

  for(int i=0; i<n; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");

  free(vet);
  return 0;
}
