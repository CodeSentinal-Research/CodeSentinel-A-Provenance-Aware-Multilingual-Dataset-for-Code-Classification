#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l = 0, r = n - 1, max_area = 0;
    while(l < r) {
        int area = (r - l) * (arr[l] < arr[r] ? arr[l] : arr[r]);
        if(area > max_area) max_area = area;
        if(arr[l] < arr[r]) l++; else r--;
    }
    printf("%d\n", max_area);
    return 0;
}
