#include<stdio.h>
int main(){
    int n,x; scanf("%d %d",&n,&x);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int lo=0,hi=n;
    while(lo<hi){int m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}
    printf("%d\n",lo);
}
