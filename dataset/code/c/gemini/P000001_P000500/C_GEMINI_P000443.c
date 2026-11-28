#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int l = 0, r = n - 1;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}