#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[10005];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int q;
        scanf("%d", &q);
        while (q--) {
            int target;
            scanf("%d", &target);
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) { found = true; break; }
            }
            printf("%s\n", found ? "Found" : "Not Found");
        }
    }
    return 0;
}