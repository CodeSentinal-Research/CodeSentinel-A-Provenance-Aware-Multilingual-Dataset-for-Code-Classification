#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int k; scanf("%d", &k);
        int width = n / k, rem = n % k, cur = 0;
        for (int i = 0; i < k; i++) {
            int sz = width + (i < rem ? 1 : 0);
            if (sz == 0) {
                printf("[]\n");
            } else {
                for (int j = 0; j < sz; j++) {
                    printf("%d%s", vals[cur + j], j == sz - 1 ? "" : " ");
                }
                printf("\n");
                cur += sz;
            }
        }
    }
    return 0;
}