#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int k; scanf("%d", &k);
        int rev = 1;
        for (int i = 0; i < n; i += k) {
            int len = (k < n - i) ? k : n - i;
            if (rev) {
                int l = i, r = i + len - 1;
                while (l < r) {
                    int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                    l++; r--;
                }
            }
            rev = !rev;
        }
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}