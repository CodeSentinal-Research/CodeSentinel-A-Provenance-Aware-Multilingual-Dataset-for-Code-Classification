#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int u_arr[m], v_arr[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u_arr[i], &v_arr[i]);
        }
        int qu, qv;
        scanf("%d %d", &qu, &qv);
        bool found = false;
        for (int i = 0; i < m; i++) {
            if ((u_arr[i] == qu && v_arr[i] == qv) || (u_arr[i] == qv && v_arr[i] == qu)) {
                found = true;
                break;
            }
        }
        printf("%s\n", found ? "YES" : "NO");
    }
    return 0;
}