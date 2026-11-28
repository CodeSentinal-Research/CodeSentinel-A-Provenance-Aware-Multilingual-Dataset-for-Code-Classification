#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n+1];
    for(int i=0; i<=n; i++) scanf("%d", &arr[i]);
    int slow = arr[0], fast = arr[0];
    do { slow = arr[slow]; fast = arr[arr[fast]]; } while(slow != fast);
    slow = arr[0];
    while(slow != fast) { slow = arr[slow]; fast = arr[fast]; }
    printf("%d\n", slow);
    return 0;
}
