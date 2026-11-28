#include <stdio.h>
int countOcc(int *a, int n, int i, int t) { if(i==n) return 0; return (a[i]==t?1:0)+countOcc(a,n,i+1,t); }
int main() { int n,t; scanf("%d%d",&n,&t); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("%d\n",countOcc(a,n,0,t)); return 0; }
