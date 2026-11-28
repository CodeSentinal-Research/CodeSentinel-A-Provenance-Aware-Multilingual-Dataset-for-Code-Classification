#include <stdio.h>
void heapify_up(int *a, int i) {
    while(i > 0) {
        int p = (i-1)/2;
        if(a[p] < a[i]) { int t=a[p]; a[p]=a[i]; a[i]=t; i=p; }
        else break;
    }
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int i, val; scanf("%d%d", &i, &val);
    a[i] = val;
    heapify_up(a, i);
    for(int j=0; j<n; j++) printf("%d%c", a[j], j==n-1?'\n':' ');
    return 0;
}
