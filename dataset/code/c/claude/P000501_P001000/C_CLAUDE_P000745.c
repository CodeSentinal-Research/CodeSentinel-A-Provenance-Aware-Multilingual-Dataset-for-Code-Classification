#include <stdio.h>
void is(int*a,int n){for(int i=1;i<n;i++){int k=a[i],j=i-1;while(j>=0&&a[j]>k){a[j+1]=a[j];j--;}a[j+1]=k;}}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);is(a,n);for(int i=0;i<n;i++)printf("%d%s",a[i],i<n-1?" ":"\n");return 0;}
