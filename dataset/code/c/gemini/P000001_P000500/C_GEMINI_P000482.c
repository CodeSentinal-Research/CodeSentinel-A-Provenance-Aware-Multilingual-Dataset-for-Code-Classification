#include <stdio.h>
#define MAX_N 10005
int nums1[MAX_N], nums2[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums1[i]);
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &nums2[i]);
        for (int i = 0; i < n; i++) {
            int idx = -1;
            for (int j = 0; j < m; j++) {
                if (nums2[j] == nums1[i]) { idx = j; break; }
            }
            int ans = -1;
            if (idx != -1) {
                for (int j = idx + 1; j < m; j++) {
                    if (nums2[j] > nums1[i]) { ans = nums2[j]; break; }
                }
            }
            printf("%d%s", ans, i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}