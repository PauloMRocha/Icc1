#include <stdio.h>
#include <stdlib.h>

int max(int *vet, int tam){
  int na, nb;
  if (tam > 1){
    na = vet[tam-1];
    nb = max(vet, tam-1);
    if(na > nb){
      return na;
    }else{
      return nb;
    }
  }else{
    return vet[0];
  }
}

int main(void){

  int v[7] = {1, 15, 13, 5, 8, 10, 4};

  printf("15 = %d\n", max(v, 7));

return 0;
}
