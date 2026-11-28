#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 1) {
            printf("0\n");
            return 0;
        }
        int* deg = (int*)calloc(n, sizeof(int));
        int* u_arr = (int*)malloc((n - 1) * sizeof(int));
        int* v_arr = (int*)malloc((n - 1) * sizeof(int));
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &u_arr[i], &v_arr[i]);
            deg[u_arr[i]]++;
            deg[v_arr[i]]++;
        }
        int* leaves = (int*)malloc(n * sizeof(int));
        int lCount = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) leaves[lCount++] = i;
        }
        int remaining = n;
        while (remaining > 2) {
            remaining -= lCount;
            int* newLeaves = (int*)malloc(n * sizeof(int));
            int nlCount = 0;
            for (int i = 0; i < lCount; i++) {
                int leaf = leaves[i];
                deg[leaf]--;
                for (int j = 0; j < n - 1; j++) {
                    if (u_arr[j] == leaf && deg[v_arr[j]] > 0) {
                        deg[v_arr[j]]--;
                        if (deg[v_arr[j]] == 1) newLeaves[nlCount++] = v_arr[j];
                    } else if (v_arr[j] == leaf && deg[u_arr[j]] > 0) {
                        deg[u_arr[j]]--;
                        if (deg[u_arr[j]] == 1) newLeaves[nlCount++] = u_arr[j];
                    }
                }
            }
            free(leaves);
            leaves = newLeaves;
            lCount = nlCount;
        }
        if (lCount == 2 && leaves[0] > leaves[1]) {
            int t = leaves[0]; leaves[0] = leaves[1]; leaves[1] = t;
        }
        for (int i = 0; i < lCount; i++) {
            printf("%d%s", leaves[i], (i == lCount - 1 ? "" : " "));
        }
        printf("\n");
        free(deg);
        free(u_arr);
        free(v_arr);
        free(leaves);
    }
    return 0;
}