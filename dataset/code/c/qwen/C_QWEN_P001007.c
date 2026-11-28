#include <stdio.h>
void heapify(int *a, int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i) { int t=a[i]; a[i]=a[largest]; a[largest]=t; heapify(a, n, largest); }
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int val; scanf("%d", &val);
    a[0] = val;
    heapify(a, n, 0);
    for(int i=0; i<n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
    return 0;
}
