#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long max_p = arr[0], min_p = arr[0], res = arr[0];
    for(int i=1; i<n; i++) {
        long long t1 = max_p * arr[i], t2 = min_p * arr[i];
        max_p = t1 > t2 ? t1 : t2;
        min_p = t1 < t2 ? t1 : t2;
        if(arr[i] > max_p) max_p = arr[i];
        if(arr[i] < min_p) min_p = arr[i];
        if(max_p > res) res = max_p;
    }
    printf("%lld\n", res);
    return 0;
}
