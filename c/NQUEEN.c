/*
		###########################
		# Author: Spandan Halder #
	    ##########################
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define false -9999
#define true 9999

int arr[9999],c=1;

void print(int n)
{
 	int i,j,itr;
 	printf("\n\nANSWER %d:\n\n",c++);
  	printf("SOLUTION VECTOR:\n\n");
	// Upper Half Printer
  	for(itr=1;itr<(n*3)+5;itr++)
  		printf("-");
  	printf("\n");

  	printf("|  ");
	for(itr=1;itr<=n;itr++)
		printf("%d  ",arr[itr]);
	printf("|");
	printf("\n");
	// Lower Half Printer
	for(itr=1;itr<(n*3)+5;itr++)
  		printf("-");
	printf("\n\nBOARD VIEW: ");
	printf("\n\n  ");
 	// Box Printer (Upper Side)
	for(i=1;i<=n*7+1;++i)
	printf("-");
	
	for(i=1;i<=n;++i)
	{
		if(i==1)
			printf("\n");
		else
		{	
			printf("\n  |");
			for(itr=1;itr<=7*n;++itr)
			{
				if(itr<7*n)
					printf("-");
				else
					printf("|");
			}
			printf("\n");
		}
		for(j=1;j<=n;++j) 
		{
			if(arr[i]==j)
				printf("  |   Q"); 
			else
				printf("  |    ");
		}
		printf("  |"); 
	}
	printf("\n  ");
	// Box Printer (Bottom Side)
	for(i=1;i<=n*7+1;++i)
	printf("-");
}
int  place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((arr[j]==i)||(abs(arr[j]-i)==abs(j-k)))
			return false;
	}
	return true;
}
void nqueen(int k,int n)
{
	int i;
	int itr;
	for(i=1;i<=n;i++)
	{
		if(place(k,i)==true)
		{
			arr[k]=i;
			if (k==n)
					print(n);
			else
				nqueen(k+1,n);
		}
	}
}


int main()
{
	int k,n,itr;
	printf("ENTER NUMBER OF QUEENS: ");
	scanf("%d",&n);

	nqueen(1,n);
	printf("\n\nFINISHED...\n");
	return 0;
	
}
