#include <stdio.h>
int count(int *a, int n, int i, int t) { if(t==0) return 1; if(i==n) return 0; return count(a,n,i+1,t-a[i])+count(a,n,i+1,t); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("%d\n",count(a,n,0,t)); return 0; }
