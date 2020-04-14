#include<stdio.h>
#include<stdlib.h>

typedef struct list_
{
	float integer;
	struct list_ * next;
}List;
void insert(List * head,float x)
{

}
int main(void)
{
	int n,aux;
	float x,soma=0;
	List * head=NULL;
	scanf("%d",&n);
	aux=n;
	while(n--)
	{

		scanf("f",&x);
		insert(head,x);
		soma+=x;
	}
	return 0;
}
