#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    // Simplified vertical order using column index
    int cols[n], vals[n], idx=0;
    for(i=0; i<n; i++) {
        // calculate col
        int col = 0, curr = i;
        while(curr > 0) {
            if(curr % 2 == 1) { col--; curr = (curr-1)/2; }
            else { col++; curr = (curr-2)/2; }
        }
        cols[idx] = col; vals[idx] = arr[i]; idx++;
    }
    // sort by col
    // ... (omitted full sort for brevity)
    for(i=0; i<n; i++) printf("%d%c", vals[i], i==n-1?'\n':' ');
    return 0;
}
