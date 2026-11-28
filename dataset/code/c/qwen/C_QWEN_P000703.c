#include <stdio.h>
int isPal(int *a, int l, int r) { if(l>=r) return 1; if(a[l]!=a[r]) return 0; return isPal(a,l+1,r-1); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("%s\n",isPal(a,0,n-1)?"true":"false"); return 0; }
