#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], res[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int stack[n], top = -1;
    for(int i=n-1; i>=0; i--) {
        while(top >= 0 && stack[top] >= arr[i]) top--;
        res[i] = top >= 0 ? stack[top] : -1;
        stack[++top] = arr[i];
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
