#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int count[100001] = {0};
    for(int i=0; i<n; i++) count[a[i]]++;
    int res[n], idx = 0;
    for(int i=0; i<=100000; i++) while(count[i]--) res[idx++] = i;
    for(int i=0; i<n; i+=2) {
        if(i+1 < n) { int t=res[i]; res[i]=res[i+1]; res[i+1]=t; }
    }
    for(int i=0; i<n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
