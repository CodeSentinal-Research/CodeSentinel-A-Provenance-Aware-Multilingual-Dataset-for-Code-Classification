#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int len = r - l + 1;
        int sub[len];
        for (int i = 0; i < len; i++) sub[i] = nums[l + i];
        qsort(sub, len, sizeof(int), cmp);
        
        int diff = sub[1] - sub[0];
        int is_arith = 1;
        for (int i = 2; i < len; i++) {
            if (sub[i] - sub[i - 1] != diff) {
                is_arith = 0;
                break;
            }
        }
        printf("%s\n", is_arith ? "YES" : "NO");
    }
    return 0;
}
