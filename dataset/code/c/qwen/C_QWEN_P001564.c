#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<=n-k; i++) {
        int window[k];
        for(int j=0; j<k; j++) window[j] = arr[i+j];
        qsort(window, k, sizeof(int), cmp);
        if(k%2 == 0) printf("%.1f ", (window[k/2-1] + window[k/2]) / 2.0);
        else printf("%.1f ", (double)window[k/2]);
    }
    printf("\n");
    return 0;
}
