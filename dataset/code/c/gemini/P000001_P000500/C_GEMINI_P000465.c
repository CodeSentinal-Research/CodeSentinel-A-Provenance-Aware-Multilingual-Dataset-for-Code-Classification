#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10005
int arr[MAX_N];
int main() {
    int n, diff;
    if (scanf("%d %d", &n, &diff) == 2) {
        diff = abs(diff);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) == diff) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        printf("%s\n", found ? "Yes" : "No");
    }
    return 0;
}