#include <stdio.h>
int check(int *a, int i, int n) { int l=2*i+1, r=2*i+2; if(l>=n) return 1; int ok=1; if(a[l]>a[i]) ok=0; if(r<n && a[r]>a[i]) ok=0; return ok && check(a,l,n) && check(a,r,n); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("%s\n",check(a,0,n)?"true":"false"); return 0; }
