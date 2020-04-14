#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char * seq=NULL;
	int n,cont=0;
	scanf("%d",&n);
	seq=(char *)malloc(sizeof(char)*n);
	for(int i=0;i<n;i++)
	{
		scanf(" %c",&seq[i]);
		if(seq[i]-'A'==i)
			cont++;
	}
	}
	if(cont>2||!cont)
		printf("There aren't the chance\n");
	else

		printf("There are the chance\n");
	printf("%d",cont);
}
