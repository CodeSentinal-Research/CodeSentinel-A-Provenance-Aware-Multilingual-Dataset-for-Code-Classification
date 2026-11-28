#include <stdio.h>
#define MAX_N 100005
int l1[MAX_N], l2[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &l1[i]);
        int m; scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &l2[i]);
        int i = 0, j = 0, first = 1;
        while (i < n && j < m) {
            if (!first) printf(" ");
            if (l1[i] <= l2[j]) printf("%d", l1[i++]);
            else printf("%d", l2[j++]);
            first = 0;
        }
        while (i < n) {
            if (!first) printf(" ");
            printf("%d", l1[i++]);
            first = 0;
        }
        while (j < m) {
            if (!first) printf(" ");
            printf("%d", l2[j++]);
            first = 0;
        }
        printf("\n");
    }
    return 0;
}