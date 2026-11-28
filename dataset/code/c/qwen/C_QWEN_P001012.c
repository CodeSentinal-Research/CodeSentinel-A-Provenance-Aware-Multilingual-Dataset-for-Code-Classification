#include <stdio.h>
void heapify(int *a, int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if(l < n && a[l] < a[smallest]) smallest = l;
    if(r < n && a[r] < a[smallest]) smallest = r;
    if(smallest != i) { int t=a[i]; a[i]=a[smallest]; a[smallest]=t; heapify(a, n, smallest); }
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int a[n+m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &a[n+i]);
    int total = n+m;
    for(int i=total/2-1; i>=0; i--) heapify(a, total, i);
    for(int i=0; i<total; i++) printf("%d%c", a[i], i==total-1?'\n':' ');
    return 0;
}
