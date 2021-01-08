#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int lowest_number(int *b, int i);
int lowest_number(int *b, int i)
{
	int k=-1;
	int a=*(b);
	while(k<i)
	{
		k++;
		if(*(b+k)<a)
		{
			a=*(b+k);
		}
	}	
	return a;
}


int main () 
{
	srand(time(NULL));
	int array_size= rand()%100;
	int vorzeichen;
	int a;
	int * b=malloc(array_size *sizeof(int));
	if(b!=NULL)
	{
		for(int i=0;i<array_size;i++)
		{
			*(b+i)=(vorzeichen = rand()%2)?rand()%1000:rand()%1000*-1;	
		}
		a=lowest_number(b, array_size);	
		printf("The lowest number is %d", a);
	}
	else
	{
		printf("No ram available exit program");
		return -99;
	}

	
return 0;
}
