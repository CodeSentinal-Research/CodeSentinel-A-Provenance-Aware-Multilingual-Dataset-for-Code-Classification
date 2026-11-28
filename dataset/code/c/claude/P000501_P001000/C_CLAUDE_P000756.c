#include <stdio.h>
int part(int*a,int lo,int hi){int p=a[hi],i=lo-1;for(int j=lo;j<hi;j++)if(a[j]<=p){i++;int t=a[i];a[i]=a[j];a[j]=t;}int t=a[i+1];a[i+1]=a[hi];a[hi]=t;return i+1;}
void qs(int*a,int lo,int hi){if(lo<hi){int pi=part(a,lo,hi);qs(a,lo,pi-1);qs(a,pi+1,hi);}}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);qs(a,0,n-1);for(int i=0;i<n;i++)printf("%d%s",a[i],i<n-1?" ":"\n");return 0;}
