#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], candidate = arr[0], count = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) {
        if(count == 0) { candidate = arr[i]; count = 1; }
        else if(arr[i] == candidate) count++;
        else count--;
    }
    printf("%d\n", candidate);
    return 0;
}
