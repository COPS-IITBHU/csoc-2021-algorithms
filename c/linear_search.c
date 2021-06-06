#include <stdio.h>
int main()
{
    int array[] = { 1,2,3,4,5};
    int i,c,d,x=5;
    int n= (sizeof(array))/(sizeof(array[0]));
    for(i=0;i<n;i++)
    {
        if(x==array[i])
        c=x;
        d=i;

    }
    if(c=x)
    printf("Element is present at index %d",d);
    else
    printf("Element is not present in array");
}