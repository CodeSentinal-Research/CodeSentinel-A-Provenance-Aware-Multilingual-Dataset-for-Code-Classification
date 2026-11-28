#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int deg[n];
        for (int i = 0; i < n; i++) deg[i] = 0;
        int u_arr[m], v_arr[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u_arr[i], &v_arr[i]);
            deg[u_arr[i]]++;
            deg[v_arr[i]]++;
        }
        int oddCount = 0, start = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] % 2 != 0) {
                oddCount++;
                if (oddCount == 1) start = i;
            }
        }
        if (oddCount != 0 && oddCount != 2) {
            printf("NONE\n");
        } else {
            bool used[m];
            for (int i = 0; i < m; i++) used[i] = false;
            int stack[m + 5];
            int sSize = 0;
            int path[m + 5];
            int pSize = 0;
            stack[sSize++] = start;

            while (sSize > 0) {
                int u = stack[sSize - 1];
                int eIdx = -1;
                for (int i = 0; i < m; i++) {
                    if (!used[i] && (u_arr[i] == u || v_arr[i] == u)) {
                        eIdx = i;
                        break;
                    }
                }
                if (eIdx != -1) {
                    used[eIdx] = true;
                    int next = (u_arr[eIdx] == u) ? v_arr[eIdx] : u_arr[eIdx];
                    stack[sSize++] = next;
                } else {
                    path[pSize++] = stack[--sSize];
                }
            }
            for (int i = pSize - 1; i >= 0; i--) {
                printf("%d%s", path[i], (i == 0 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}