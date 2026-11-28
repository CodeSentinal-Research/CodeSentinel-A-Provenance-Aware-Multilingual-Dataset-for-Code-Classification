#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[100000], max_val=-2000000000, idx=0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]>max_val) { max_val=arr[i]; idx=i; } }
    printf("%d\n", idx);
    return 0;
}
