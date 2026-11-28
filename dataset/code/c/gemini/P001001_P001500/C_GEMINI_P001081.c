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
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (deg[i] % 2 != 0) { ok = false; break; }
        }
        if (!ok) {
            printf("NONE\n");
        } else {
            bool used[m];
            for (int i = 0; i < m; i++) used[i] = false;
            int stack[m + 5];
            int sSize = 0;
            int circuit[m + 5];
            int cSize = 0;
            stack[sSize++] = 0;

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
                    circuit[cSize++] = stack[--sSize];
                }
            }
            for (int i = cSize - 1; i >= 0; i--) {
                printf("%d%s", circuit[i], (i == 0 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}