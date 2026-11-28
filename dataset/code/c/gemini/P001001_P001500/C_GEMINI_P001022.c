#include <stdio.h>

void decreaseKey(int arr[], int idx, int newVal) {
    arr[idx] = newVal;
    int i = idx;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] < arr[p]) {
            int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
}

int main() {
    int n, idx, newVal;
    if (scanf("%d %d %d", &n, &idx, &newVal) == 3 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        decreaseKey(arr, idx, newVal);
        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}