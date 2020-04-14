#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);



	

	for(int a=1; a <= 2*n; a++){

                for (int b=a; b <= n ; b++){
                        printf("¬");

			 printf("\n");
                }
		for (int b=a; b > 0 ; b--){
                        printf("¬");

			 printf("\n");
		}

	}
}
