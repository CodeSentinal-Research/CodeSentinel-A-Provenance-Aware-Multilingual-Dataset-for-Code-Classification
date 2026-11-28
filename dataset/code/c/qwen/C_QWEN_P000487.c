#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int height[100000], left[100000], right[100000];
    for(int i=0; i<n; i++) scanf("%d", &height[i]);
    left[0]=height[0];
    for(int i=1; i<n; i++) left[i] = height[i]>left[i-1] ? height[i] : left[i-1];
    right[n-1]=height[n-1];
    for(int i=n-2; i>=0; i--) right[i] = height[i]>right[i+1] ? height[i] : right[i+1];
    long long water=0;
    for(int i=0; i<n; i++) {
        int min_h = left[i]<right[i] ? left[i] : right[i];
        water += min_h - height[i];
    }
    printf("%lld\n", water);
    return 0;
}
