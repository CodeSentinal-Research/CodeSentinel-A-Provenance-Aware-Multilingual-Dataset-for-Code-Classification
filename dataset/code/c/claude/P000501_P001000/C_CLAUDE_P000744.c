#include <stdio.h>
void ss(int*a,int n){for(int i=0;i<n-1;i++){int mi=i;for(int j=i+1;j<n;j++)if(a[j]<a[mi])mi=j;int t=a[mi];a[mi]=a[i];a[i]=t;}}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);ss(a,n);for(int i=0;i<n;i++)printf("%d%s",a[i],i<n-1?" ":"\n");return 0;}
