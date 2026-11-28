#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], low = 0, mid = 0, high = n - 1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    while(mid <= high) {
        if(arr[mid] == 0) { int t = arr[low]; arr[low] = arr[mid]; arr[mid] = t; low++; mid++; }
        else if(arr[mid] == 1) mid++;
        else { int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t; high--; }
    }
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
