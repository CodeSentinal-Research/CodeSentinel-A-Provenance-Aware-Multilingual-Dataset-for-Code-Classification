#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n], sorted[n], pos[n];
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); sorted[i] = arr[i]; }
    qsort(sorted, n, sizeof(int), cmp);
    for(int i=0; i<n; i++) pos[sorted[i]] = i;
    int swaps = 0;
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    for(int i=0; i<n; i++) {
        if(visited[i] || pos[arr[i]] == i) continue;
        int cycle_size = 0, j = i;
        while(!visited[j]) { visited[j] = 1; j = pos[arr[j]]; cycle_size++; }
        if(cycle_size > 0) swaps += (cycle_size - 1);
    }
    printf("%d\n", swaps);
    return 0;
}
