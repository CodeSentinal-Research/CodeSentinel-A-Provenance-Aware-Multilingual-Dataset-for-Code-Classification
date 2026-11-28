#include<stdio.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int bs(int*a,int n,int x){int l=0,r=n-1;while(l<=r){int m=(l+r)/2;if(a[m]==x)return 1;if(a[m]<x)l=m+1;else r=m-1;}return 0;}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);qsort(a,n,sizeof(int),cmp);int q;scanf("%d",&q);while(q--){int x;scanf("%d",&x);printf("%s\n",bs(a,n,x)?"Found":"Not Found");}}
