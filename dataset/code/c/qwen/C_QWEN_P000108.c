#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], sorted = 1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<n; i++) if(arr[i] > arr[i-1]) sorted = 0;
    printf("%s\n", sorted ? "Sorted" : "Not Sorted");
    return 0;
}
