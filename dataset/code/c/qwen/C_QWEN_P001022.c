#include <stdio.h>
void heapify_down(int *a, int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if(l < n && a[l] < a[smallest]) smallest = l;
    if(r < n && a[r] < a[smallest]) smallest = r;
    if(smallest != i) { int t=a[i]; a[i]=a[smallest]; a[smallest]=t; heapify_down(a, n, smallest); }
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int i, val; scanf("%d%d", &i, &val);
    a[i] = val;
    heapify_down(a, n, i);
    for(int j=0; j<n; j++) printf("%d%c", a[j], j==n-1?'\n':' ');
    return 0;
}
