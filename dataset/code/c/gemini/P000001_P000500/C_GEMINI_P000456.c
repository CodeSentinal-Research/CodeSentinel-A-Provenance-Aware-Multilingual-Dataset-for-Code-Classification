#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int arr[MAX_N];
bool canFinish(int* a, int n, int h, long long speed) {
    long long hours = 0;
    for (int i = 0; i < n; i++) hours += (a[i] + speed - 1) / speed;
    return hours <= h;
}
int main() {
    int n, h;
    if (scanf("%d %d", &n, &h) == 2) {
        int max_v = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > max_v) max_v = arr[i];
        }
        long long l = 1, r = max_v, ans = max_v;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (canFinish(arr, n, h, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}