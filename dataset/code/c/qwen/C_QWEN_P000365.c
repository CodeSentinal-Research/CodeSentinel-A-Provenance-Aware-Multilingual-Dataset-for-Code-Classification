#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[100000], min_val=2000000000, idx=0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]<min_val) { min_val=arr[i]; idx=i; } }
    printf("%d\n", idx);
    return 0;
}
