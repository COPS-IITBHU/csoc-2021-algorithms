#include <bits/stdc++.h>
using namespace std;

int MedianOfTwoSortedArrays(int a[],int b[],int asize, int bsize){
    int i = 0; 
    int j = 0; 
    int count;
    int m1 = -1, m2 = -1;

    if((bsize + asize) % 2 == 1)
    {
        for (count = 0; count <= (asize + bsize)/2; count++)
        {
            if(i != asize && j != bsize)
            {
                m1 = (a[i] > b[j]) ? b[j++] : a[i++];
            }
            else if(i < asize)
            {
                m1 = a[i++];
            }
            else
            {
                m1 = b[j++];
            }
        }
        return m1;
    }

    else
    {
        for (count = 0; count <= (asize + bsize)/2; count++)
        {
            m2 = m1;
            if(i != asize && j != bsize)
            {
                m1 = (a[i] > b[j]) ? b[j++] : a[i++];
            }
            else if(i < asize)
            {
                m1 = a[i++];
            }
            else
            {
                m1 = b[j++];
            }
        }
        return (m1 + m2)/2;
    }
    
}
