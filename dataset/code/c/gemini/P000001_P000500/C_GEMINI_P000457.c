#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int arr[MAX_N];
bool check(int* a, int n, int thresh, int div) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += (a[i] + div - 1) / div;
    return sum <= thresh;
}
int main() {
    int n, thresh;
    if (scanf("%d %d", &n, &thresh) == 2) {
        int max_v = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > max_v) max_v = arr[i];
        }
        int l = 1, r = max_v, ans = max_v;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (check(arr, n, thresh, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}