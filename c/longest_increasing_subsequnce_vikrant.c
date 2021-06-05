#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);
    int Q[num];

    for(int i=0; i<num; i++)
        scanf("%d",&Q[i]);
    int max=1, temp=1;
    
    for(int i=0; i<num-1; i++)
    {
        if(Q[i]<=Q[i+1])
            temp++;
        else{
            if(max<temp)
                max=temp;
            temp=1;
        }

    }

    if(max<temp)
        max=temp;
    
    printf("Length of longest subsequence : %d",max);
}