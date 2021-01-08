#include <stdio.h>
#include <malloc.h>
#include <math.h>
int Sum_of_Sum(int *b, int n);
int gaus(int n);
int Sum_of_Sum(int *b, int n)
{
	int a=0;
	for(int i=0; i<=n;i++)
	{
		a +=i;
		*(b+i)=a;
	}
	return a;
}
int gaus(int n)
{
	int a=0;
	a=(pow(n,2)+n)/2;
	return a;
}



int main()
{
	int n;
	printf("Bitte geben Sie eine Zahl ein von der Sie Summe aller Zahlen haben: ");
	scanf("%d", &n);
	int *b= malloc(n*sizeof(int));
	int s=Sum_of_Sum(b, n);
	printf("\nDie Summe ist %d",s);
	int k=gaus(n);
	printf("\n Der Gaus ist %d",k);
	if(s==k)
		{
			printf("\n Die Formel stimmt!!!");
		}
	printf("\nDie Zwischenergebnisse sind.");
	for(int i=1;i<=n;i++)
	{
		printf("\n%d",*(b+i));
	}
	

	b=NULL;
	free(b);
	return 0;
}
