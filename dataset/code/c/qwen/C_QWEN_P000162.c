#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[n], count = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i] + arr[j] == target) count++;
    printf("%d\n", count);
    return 0;
}
