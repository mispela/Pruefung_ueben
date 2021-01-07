#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int durch_3_teilbar(int *b, int i);
int durch_3_teilbar(int *b, int i)
{



	static int k=-1;
	k++;
	if(k==i)
	{
		return -998;
	}
	if((*(b+k)%3)==0)
	{
		return*(b+k);
	}
	
	return -1;
}


int main () 
{
	int m;
	srand(time(NULL));
	int array_size =rand()%10;
	printf("array_size=%d\n",array_size);
	int *b = malloc(array_size * sizeof(int));
	if(b==NULL)
	{
		printf("No ram availalbe");
	}
	int r;
	for(int i=0;i<array_size;i++)
	{
		r=rand()%2?rand()%100:rand()%100*-1;
		*(b+i)=r;
	}
	int d=-1;
	while((m=durch_3_teilbar(b, array_size))!=-998)
	{
		d++;
		if(m!=-1)
		{
			printf("%d ist durch 3 teilbar\n",m);
		}
		else
		{
			printf("%d ist NICHT durch 3 Teilbar\n",*(b+d));
		}
	}
	b=NULL;
	free(b);
return 0;
}
