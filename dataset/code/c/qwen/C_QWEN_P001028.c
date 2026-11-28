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
    int i; scanf("%d", &i);
    a[i] = a[n-1]; n--;
    if(i < n) { heapify(a, n, i); while(i>0 && a[(i-1)/2] < a[i]) { int t=a[i]; a[i]=a[(i-1)/2]; a[(i-1)/2]=t; i=(i-1)/2; } }
    for(int j=0; j<n; j++) printf("%d%c", a[j], j==n-1?'\n':' ');
    return 0;
}
