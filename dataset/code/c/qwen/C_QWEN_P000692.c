#include <stdio.h>
int sorted(int *a, int i, int n) { if(i==n-1) return 1; if(a[i]>a[i+1]) return 0; return sorted(a, i+1, n); }
int main() { int n; scanf("%d", &n); int a[n]; for(int i=0;i<n;i++) scanf("%d", &a[i]); printf("%s\n", sorted(a, 0, n)?"true":"false"); return 0; }
