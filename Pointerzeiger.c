#include <stdio.h>
#include <malloc.h>

int main()
{
	int a = 30, b = 0;
	char *ptr;
	char Array[30] = "This is just a Test_";
	ptr = (char *) malloc(a *sizeof(char));
	for(int i = b; i<a; i++)
	{
		if(Array[i-1]=='_')
			break;
		
		*(ptr + i) = Array[i];
	}
	

	for(int k = b; k<=a; k++)
	{
		if(*(ptr + k)=='_')
			break;
		printf("%c", *(ptr + k));	
	}
	free(ptr);
	ptr = NULL;
	return 0;
}
