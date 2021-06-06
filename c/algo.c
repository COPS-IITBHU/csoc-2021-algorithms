#include <stdio.h>

int main()
{
    int n,m,l,i,t;
    printf("enter size of array 1:");
    scanf("%d",&n);
    printf("enter size of array 2:");
    scanf("%d",&m);
    int a[n],b[m];
    l=m+n;
    int c[l];
    printf("enter elements of array 1\n");
    for(i=0;i<n;i++)
    {    
        printf("element %d -", i);
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    printf("enter elements of array 2\n");
    for(i=0;i<m;i++)
    {    
        printf("element %d -", i);
        scanf("%d",&b[i]);
        c[n+i]=b[i];
    }
    for(int i=0;i<l;i++)
    {
        for(int j=i;j<l;j++)
        {
            if(c[i]>c[j])
             {
                t=c[i];
                c[i]=c[j];
                c[j]=t;
             }
            else    
              continue;
        }
    }
    printf("the merged list is -");
    for(i=0;i<l;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
    if(l%2!=0)
    {
        float f=c[(l-1)/2];
        printf("median is:- %f \n",f);
    }
    else
    {
        float f=(c[l/2]+c[l/2-1])/2.0;
        printf("median is:- %f \n",f);
    }    
    return 0;    
}