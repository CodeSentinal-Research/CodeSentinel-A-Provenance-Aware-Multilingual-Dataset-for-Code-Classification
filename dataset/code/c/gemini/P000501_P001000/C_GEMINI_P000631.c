#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int found = 0;
        int vals[100005];
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        int target; scanf("%d", &target);
        for (int i = 0; i < n; i++) {
            if (vals[i] == target) { found = 1; break; }
        }
        printf("%s\n", found ? "true" : "false");
    }
    return 0;
}