#include <stdio.h>

int main(void){
	int num;
	float n, soma = 0;
		
	printf("digite quantos numeros serão somados, e depois digite os numeros\n");
	scanf ("%d", &num);
	printf("+++++++++++++++++++++++++++\n");

	for(int i=0; i != num; i++){
		scanf("%f", &n);
		soma += n;
	}

	printf("A soma é %.2f\n", soma);
	return 0;
}
