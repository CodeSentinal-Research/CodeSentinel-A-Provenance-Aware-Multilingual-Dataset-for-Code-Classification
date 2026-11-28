#include <stdio.h>
#include <limits.h>

int findSecondSmallest(const int arr[], int n, int *found) {
    long long first = LLONG_MAX, second = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == LLONG_MAX) {
        *found = 0;
        return 0;
    }
    *found = 1;
    return (int)second;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int found = 0;
        int res = findSecondSmallest(arr, n, &found);
        if (found) printf("%d\n", res);
        else printf("Does not exist\n");
    }
    return 0;
}