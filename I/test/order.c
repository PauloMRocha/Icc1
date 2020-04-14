#include <stdio.h>

int main(void){

	float p1[6]={7,10,0,10,8,10}, p2[6] ={6,8.5,3,10,9,10}, p3[6]={7,10,1,9,5,10}
	float final[6];
	char conceito[6];

	for(int i=0; i<6; i++){
		final[i] = (p1[i]+p2[i]+p3[i])/3;

		if(final[i] > 9){
			conceito[i] = "A";
		}else{
			if(final[i] > 7.5){
				conceito[i] = "B";
			}else{
				if(final[i] > 5){
					conceito[i] = "C";
				}else{
					conceito[i] = "R";
				}
			}
		}
	}
	printf("%s", conceito);
	printf("\n");
	// conceito[7] = "\0";

	return 0;
}
