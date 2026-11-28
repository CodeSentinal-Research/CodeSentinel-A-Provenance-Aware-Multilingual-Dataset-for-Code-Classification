#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int is_pal = 1;
        for (int i = 0; i < n / 2; i++) {
            if (vals[i] != vals[n - 1 - i]) { is_pal = 0; break; }
        }
        printf("%s\n", is_pal ? "true" : "false");
    }
    return 0;
}