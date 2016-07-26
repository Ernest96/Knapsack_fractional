#include <stdio.h>

struct Obiect
{
	int masa;
	int val;
	float coef;


}O[20],temp;

int main()
{
	int nr,i,j;
	float V=0, M=0 , Mmax;

	printf("\t\t\t GREEDY ALGORITHM\r\n");
	printf("\t\t\t Problema rucsacului cu elemente separabile\r\n");

	printf("\r\n Introdu capacitatea maxima a rucsacului : ");
	scanf("%f",&Mmax);

	printf("\r\n Introdu numarul de obiecte: ");
	scanf("%d",&nr);

	for(i=0;i<nr;i++)
	{
		printf("\r\nIntrodu masa pentru obiectul nr  %d : ",i+1);
		scanf("%d",&O[i].masa);

		printf("\r\nIntrodu valoarea obiectului nr %d :",i+1);
		scanf("%d",&O[i].val);

		O[i].coef=(float)O[i].val / O[i].masa;

	}

	for(j=nr;j>0;j--)   // SORTARE DUPA COEFICIENTI
	for(i=0;i<j;i++)
	if(O[i].coef < O[i+1].coef)
	{
		temp=O[i];
		O[i]=O[i+1];
		O[i+1]=temp;

	}	

	//GREEDY ALGORITHM
	for(i=0;i<nr && M<Mmax;i++)
		if(M+O[i].masa <= Mmax )
		{
			V=(float)V+O[i].val;
			M=(float)M+O[i].masa;

		}

		else

		{
			V=(float)V+O[i].coef*(Mmax-M);
			M=(float)Mmax;

		}

printf("\r\nValoarea maxima ce poate fi luata : %f ",V);
printf("\r\nMasa finala : %f",M);


}