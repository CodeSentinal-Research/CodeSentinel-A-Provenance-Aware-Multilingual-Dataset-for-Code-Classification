#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    int ones = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]==1) ones++; }
    if(ones == 0) { printf("0\n"); return 0; }
    int cur = 0;
    for(int i=0; i<ones; i++) if(arr[i]==1) cur++;
    int max_ones = cur;
    for(int i=ones; i<n; i++) {
        if(arr[i]==1) cur++;
        if(arr[i-ones]==1) cur--;
        if(cur > max_ones) max_ones = cur;
    }
    printf("%d\n", ones - max_ones);
    return 0;
}
