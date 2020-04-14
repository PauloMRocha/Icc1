#include<stdio.h>
#include<stdlib.h>
int ak(int m,int n)
{
	if(m==0)
		return n+1;
	if(m>0 && n==0)
		return ak(m-1,1);
	else
		return ak(m-1,ak(m,n-1));
}

int main(void)
{
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",ak(x,y));
	return 0;
}
