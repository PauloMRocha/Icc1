#include <stdio.h>

int fibg(int n, int i, int f){
  if(n==0) return i;
  if(n==1) return f;

  return (fibg(n-1, i, f) + fibg(n-2, i, f));
}
void ab(){
  char vet[7] = {'a','b','b','a','a','a','b'};
  int i=0, j=6;

  do{
    while(vet[i] == 'a') i++;
    while(vet[j] == 'b') j--;

    if(i<j){
      vet[i]='a';
      vet[j]='b';
    }
  }while(i<j);
  for(int i=0; i<7; i++){
    printf("%c ", vet[i]);
  }
}
int main(void){
  printf("%d\n", fibg(4, 3, 8));
  ab();
}
