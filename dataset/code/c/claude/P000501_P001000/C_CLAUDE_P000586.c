#include<stdio.h>
void rev(int*a,int l,int r){while(l<r){int t=a[l];a[l]=a[r];a[r]=t;l++;r--;}}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int k;scanf("%d",&k);
for(int i=0;i+k<=n;i+=k)rev(a,i,i+k-1);
for(int i=0;i<n;i++)printf("%d%c",a[i],i<n-1?' ':'\n');}
