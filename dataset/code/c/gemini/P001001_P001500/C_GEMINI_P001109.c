#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int u_arr[m], v_arr[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u_arr[i], &v_arr[i]);
        }
        int colors[n];
        for (int i = 0; i < n; i++) scanf("%d", &colors[i]);

        bool valid = true;
        for (int i = 0; i < m; i++) {
            if (colors[u_arr[i]] == colors[v_arr[i]]) {
                valid = false;
                break;
            }
        }
        printf("%s\n", valid ? "VALID" : "INVALID");
    }
    return 0;
}