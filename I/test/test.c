#include <stdio.h>

float f1(unsigned char a){
	float x = a/255.0f;
	return x;
}


int main(void){
	int x;
	scanf("%d", &x);
	int v = x % 256;
	float a = f1((unsigned char)v);
	printf("%f\n%d\n", a,v);

	return 0;
}
