#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N], counts[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &vals[i]);
        }
        int first = 1;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) if (vals[j] == vals[i]) c++;
            if (c == 1) {
                if (!first) printf(" ");
                printf("%d", vals[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}