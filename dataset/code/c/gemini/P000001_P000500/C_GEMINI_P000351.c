#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[100005];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int x;
        scanf("%d", &x);
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) { found = true; break; }
        }
        printf("%s\n", found ? "Found" : "Not Found");
    }
    return 0;
}