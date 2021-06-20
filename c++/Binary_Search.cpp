#include<stdio.h>


// calculating square root using binary search

float square_root(float n);

float max(float a,float b);

int main()
{
	float n;
	scanf("%f",&n);
	if(n<0){printf("number should be positive\n");return 0;}
	printf("%f",square_root(n));
}

float max(float a,float b)
{
	if(a>b)return a;
	return b;
}

float square_root(float n)
{
	float u=max(1,n),l=0,uc,lc,c;
	while(1)
	{
		uc=u,lc=l;
		c=(u+l)/2.0;
		if(c*c<n)
			l=c;
		if(c*c>n)
			u=c;
		if(c*c==n||(uc==u && lc==l))
			break;
	}
	return c;
}
