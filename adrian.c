#include<stdio.h>
#include<stdlib.h>

int aranjare(int *v,int n)
{
    int a[n],b[n],x=0,y=0;
    for(int i=0;i<n;i++)
    if(v[i]%2) x++,a[x]=v[i];
    for(int i=0;i<n;i++)
    if(v[i]%2==0) y++,b[y]=v[i];
    for(int i=0;i<x;i++)
    v[i]=a[i+1];
    for(int i=0;i<y;i++)
    v[x+i]=b[i+1];
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);

    aranjare(a, n);
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);

    return 0;
}
