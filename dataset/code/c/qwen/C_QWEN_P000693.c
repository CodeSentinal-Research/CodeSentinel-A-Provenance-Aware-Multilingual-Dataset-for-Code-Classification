#include <stdio.h>
int search(int *a, int i, int n, int t) { if(i==n) return 0; if(a[i]==t) return 1; return search(a, i+1, n, t); }
int main() { int n, t; scanf("%d %d", &n, &t); int a[n]; for(int i=0;i<n;i++) scanf("%d", &a[i]); printf("%s\n", search(a, 0, n, t)?"true":"false"); return 0; }
