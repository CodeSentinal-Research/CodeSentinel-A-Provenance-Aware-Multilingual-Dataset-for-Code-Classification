#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long sum = 0;
    int max_len = 0, left = 0;
    for(int right=0; right<n; right++) {
        sum += arr[right];
        while(sum > k) sum -= arr[left++];
        if(sum == k && right - left + 1 > max_len) max_len = right - left + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
