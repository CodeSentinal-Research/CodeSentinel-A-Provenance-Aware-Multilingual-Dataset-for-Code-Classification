#include <stdio.h>
void heapify_up(int *a, int i) {
    while(i > 0) {
        int p = (i-1)/2;
        if(a[p] > a[i]) { int t=a[p]; a[p]=a[i]; a[i]=t; i=p; }
        else break;
    }
}
int main() {
    int n; scanf("%d", &n);
    int a[n+1]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int val; scanf("%d", &val);
    a[n] = val;
    heapify_up(a, n);
    for(int i=0; i<=n; i++) printf("%d%c", a[i], i==n?'\n':' ');
    return 0;
}
