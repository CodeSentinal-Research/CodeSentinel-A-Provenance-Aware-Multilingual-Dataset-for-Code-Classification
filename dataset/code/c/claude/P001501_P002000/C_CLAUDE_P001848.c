#include <stdio.h>
int bs(int*a,int n,int t){int lo=0,hi=n-1;while(lo<=hi){int m=lo+(hi-lo)/2;if(a[m]==t)return m;if(a[m]<t)lo=m+1;else hi=m-1;}return -1;}
int main(){int n,t;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);scanf("%d",&t);int r=bs(a,n,t);if(r==-1)printf("Not Found\n");else printf("%d\n",r);return 0;}
