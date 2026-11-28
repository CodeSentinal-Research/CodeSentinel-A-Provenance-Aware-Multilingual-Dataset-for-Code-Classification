#include <stdio.h>
int main() {
    int n, goal; scanf("%d %d", &n, &goal);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int count = 0;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum == goal) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
