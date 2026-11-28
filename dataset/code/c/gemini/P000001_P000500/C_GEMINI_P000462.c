#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n - 1; i++) scanf("%d", &arr[i]);
        int diff = (arr[n - 2] - arr[0]) / (n - 1);
        for (int i = 0; i < n - 2; i++) {
            if (arr[i + 1] - arr[i] != diff) {
                printf("%d\n", arr[i] + diff);
                return 0;
            }
        }
        printf("%d\n", arr[n - 2] + diff);
    }
    return 0;
}