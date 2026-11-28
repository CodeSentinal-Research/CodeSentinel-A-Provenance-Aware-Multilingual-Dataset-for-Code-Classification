#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int h = 0, temp = n;
    while(temp > 1) { temp /= 2; h++; }
    int ok = 1;
    for(int i=n/2; i<n; i++) {
        // check if leaf
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
