#include <stdio.h>
#include <malloc.h>
#include <string.h>
int Buchstaben_zuweisen_gross(char *Buchstaben_gross);
int Buchstaben_zuweisen_klein(char *Buchstaben_klein);
int Zahlen_zuweissen(char *Zahlen);
int create_passwords(char *Brute, char *Buchstaben_gross,char *Buchstaben_klein,char *Zahlen,int n);
int Buchstaben_zuweisen_gross(char *Buchstaben_gross)
{
	int k=-1;
	*(Buchstaben_gross+(++k))='A', *(Buchstaben_gross+(++k))='B', *(Buchstaben_gross+(++k))='C', *(Buchstaben_gross+(++k))='D', *(Buchstaben_gross+(++k))='E', *(Buchstaben_gross+(++k))='F', *(Buchstaben_gross+(++k))='G', *(Buchstaben_gross+(++k))='H', *(Buchstaben_gross+(++k))='I', *(Buchstaben_gross+(++k))='J', *(Buchstaben_gross+(++k))='K', *(Buchstaben_gross+(++k))='L', *(Buchstaben_gross+(++k))='M', *(Buchstaben_gross+(++k))='N', *(Buchstaben_gross+(++k))='O', *(Buchstaben_gross+(++k))='P', *(Buchstaben_gross+(++k))='Q', *(Buchstaben_gross+(++k))='R', *(Buchstaben_gross+(++k))='S', *(Buchstaben_gross+(++k))='T', *(Buchstaben_gross+(++k))='U', *(Buchstaben_gross+(++k))='V', *(Buchstaben_gross+(++k))='W', *(Buchstaben_gross+(++k))='X', *(Buchstaben_gross+(++k))='Y', *(Buchstaben_gross+(++k))='Z';
	
	return 0;
}
int Buchstaben_zuweisen_klein(char *Buchstaben_klein)
{
	int k=-1;
	*(Buchstaben_klein+(++k))='a', *(Buchstaben_klein+(++k))='b', *(Buchstaben_klein+(++k))='c', *(Buchstaben_klein+(++k))='d', *(Buchstaben_klein+(++k))='e', *(Buchstaben_klein+(++k))='f', *(Buchstaben_klein+(++k))='g', *(Buchstaben_klein+(++k))='h', *(Buchstaben_klein+(++k))='i', *(Buchstaben_klein+(++k))='j', *(Buchstaben_klein+(++k))='k', *(Buchstaben_klein+(++k))='l', *(Buchstaben_klein+(++k))='m', *(Buchstaben_klein+(++k))='n', *(Buchstaben_klein+(++k))='o', *(Buchstaben_klein+(++k))='p', *(Buchstaben_klein+(++k))='q', *(Buchstaben_klein+(++k))='r', *(Buchstaben_klein+(++k))='s', *(Buchstaben_klein+(++k))='t', *(Buchstaben_klein+(++k))='u', *(Buchstaben_klein+(++k))='v', *(Buchstaben_klein+(++k))='w', *(Buchstaben_klein+(++k))='x', *(Buchstaben_klein+(++k))='y', *(Buchstaben_klein+(++k))='z';

	return 0;
}
int Zahlen_zuweissen(char *Zahlen)
{
	int k=0;
		*(Zahlen)='0',*(Zahlen+(++k))='1',*(Zahlen+(++k))='2',*(Zahlen+(++k))='3',*(Zahlen+(++k))='4',*(Zahlen+(++k))='5',*(Zahlen+(++k))='6',*(Zahlen+(++k))='7',*(Zahlen+(++k))='8',*(Zahlen+(++k))='9';
	return 0;
}

int create_passwords(char *Brute,char *Buchstaben_gross,char *Buchstaben_klein,char *Zahlen,int n)
{

	static int i=-1;
	static int Stelle=-1;
	static int d=0;
	static int m=0;
	static int f=0;
	i++;
	if(d==0&&m==0)
	{
		*(Brute+(++Stelle+1))= '\0';
	}
		
	//Checks einbauen die beim ersten übergang true schalten und eine while in while...
	while(f<=63)
	{
		if(m==63)
		{
			m=0;
		}
				
		if(f<26)
		{
			*(Brute+(Stelle-2))=*(Buchstaben_gross+f);
		}
		else if(m<53)
		{
			*(Brute+(Stelle-2))=*(Buchstaben_klein+(f-26));
		}
		else if(m<63)
		{
			*(Brute+(Stelle-2))=*(Zahlen+(f-52));
		}
	

	while(m<=63)
	{
		if(d==63)
		{
			d=0;
		}
				
		if(m<26)
		{
			*(Brute+(Stelle-1))=*(Buchstaben_gross+m);
		}
		else if(m<53)
		{
			*(Brute+(Stelle-1))=*(Buchstaben_klein+(m-26));
		}
		else if(m<63)
		{
			*(Brute+(Stelle-1))=*(Zahlen+(m-52));
		}
	
		if(m==63)
			{
				f++;
				if(f==1)
				{
					*(Brute+(++Stelle+1))= '\0';
				}
			}
	
	while(d<=62)
	{
		if(d<26)
		{
			*(Brute+Stelle)=*(Buchstaben_gross+d);
			++d;
			return 0;
		}
		else if(d<52)
		{
			*(Brute+Stelle)=*(Buchstaben_klein+(d-26));
			++d;
			return 0;
		}
		else if(d<62)
		{
			*(Brute+Stelle)=*(Zahlen+(d-52));
			++d;
			
			return 0;
		}
		else if(d==62)
		{
			m++;
			++d;
			if(m==1&&f==0)
			{	
				
				*(Brute+(++Stelle+1))= '\0';
			}
		
		}
	}//Ende innere While
	}//Ende außere While
	}//Ende 3te While schleife
	
	/*
	if(i<26)
	{
		*(Brute+Stelle)=*(Buchstaben_gross+i);
	}
	else if(i<52)
	{
		*(Brute+Stelle)=*(Buchstaben_klein+(i-26));
	}
	else if(i<62)
	{
		*(Brute+Stelle)=*(Zahlen+(i-52));
	}
	*/

	return 0;
}

int main()
{
	char *Password="001";
	int Buchstaben_anzahl =26;
	int Zahlen_ziffer_anzahl=10;
	int n;
	printf("Wie viele buchstaben sollen gecrackt werden?");
	scanf("%d",&n);
	//Create arrays;
	char *Buchstaben_gross=malloc(Buchstaben_anzahl*sizeof(char));
	char *Buchstaben_klein=malloc(Buchstaben_anzahl*sizeof(char));
	char *Zahlen=malloc(Zahlen_ziffer_anzahl*sizeof(char));
	char *Brute=malloc(n*sizeof(char));
	if(Buchstaben_gross!=NULL && Buchstaben_klein!=NULL && Zahlen !=NULL)
	{
		Buchstaben_zuweisen_gross(Buchstaben_gross);
		Buchstaben_zuweisen_klein(Buchstaben_klein);
		Zahlen_zuweissen(Zahlen);
	}
	else
	{
		printf("No ram available");
		return -1;
	}
	int m=-1;
	int permutationen=(Buchstaben_anzahl+Buchstaben_anzahl+Zahlen_ziffer_anzahl);
	while(m<=9999999)
	{
		m++;
		create_passwords(Brute, Buchstaben_gross,Buchstaben_klein,Zahlen,n);
		printf("Brute=%s\n", Brute);
		if((strcmp(Password, Brute))==0)
		{
			printf("Das Password ist %s", Brute);

			//free(Buchstaben_gross), Buchstaben_gross=NULL, free(Buchstaben_klein) ,Buchstaben_klein=NULL, free(Zahlen) Zahlen=NULL, free(Brute), Brute=NULL, free(Password), Password=NULL;
			return 0;
		}
	}
	//free(Buchstaben_gross), Buchstaben_gross=NULL, free(Buchstaben_klein) ,Buchstaben_klein=NULL, free(Zahlen) Zahlen=NULL, free(Brute), Brute=NULL, free(Password), Password=NULL;
	/*
	//Test kann gelöscht werden
	printf("Password ist=%s\n",Password);
	for(int i=0; i<Buchstaben_anzahl;i++)
	{
		
		printf("\n%d %c %c",i, *(Buchstaben_gross+i), *(Buchstaben_klein+i));
		if(i<10)
			printf(" Zahl=%d", *(Zahlen+i));	
	}*/


	
	
	
	return 0;
}
