#include<stdio.h>
int main(){int n;scanf("%d",&n);int h[n],L[n],R[n];for(int i=0;i<n;i++)scanf("%d",&h[i]);L[0]=h[0];for(int i=1;i<n;i++)L[i]=L[i-1]>h[i]?L[i-1]:h[i];R[n-1]=h[n-1];for(int i=n-2;i>=0;i--)R[i]=R[i+1]>h[i]?R[i+1]:h[i];long long w=0;for(int i=0;i<n;i++)w+=(L[i]<R[i]?L[i]:R[i])-h[i];printf("%lld\n",w);}
