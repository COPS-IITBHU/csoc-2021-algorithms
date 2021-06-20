#include<stdio.h>
int main()
{
    int n,*a,*b,i,j;
    int max=0;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    b=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        b[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        if((b[j]+1)>b[i] && a[j]<a[i])
             b[i]=b[j]+1;
    }
    for(i=0;i<n;i++)
       if(max<b[i])
          max=b[i];
    printf("The Length of the longest increasing subsequence is %d\n",max);
    return 0;
}