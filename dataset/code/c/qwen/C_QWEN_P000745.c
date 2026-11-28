#include <stdio.h>
void sort(int *a, int i, int n) { if(i>=n) return; int key=a[i], j=i-1; while(j>=0 && a[j]>key) { a[j+1]=a[j]; j--; } a[j+1]=key; sort(a,i+1,n); }
int main() { int n; scanf("%d",&n); int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,1,n); for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); return 0; }
