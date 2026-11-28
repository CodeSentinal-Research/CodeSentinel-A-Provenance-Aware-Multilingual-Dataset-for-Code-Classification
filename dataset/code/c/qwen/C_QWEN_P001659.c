#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    // Populate next right pointers logic
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
