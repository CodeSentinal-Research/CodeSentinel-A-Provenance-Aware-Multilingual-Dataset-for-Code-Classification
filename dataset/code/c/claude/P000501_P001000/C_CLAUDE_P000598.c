#include<stdio.h>
void rev(int*a,int l,int r){while(l<r){int t=a[l];a[l]=a[r];a[r]=t;l++;r--;}}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int l,r;scanf("%d %d",&l,&r);
rev(a,l-1,r-1);for(int i=0;i<n;i++)printf("%d%c",a[i],i<n-1?' ':'\n');}
