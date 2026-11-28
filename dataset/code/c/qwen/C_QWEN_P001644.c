#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int first = 1;
    // Left boundary
    int i = 1;
    while(i < n) { if(arr[i] != -1) { if(!first) printf(" "); printf("%d", arr[i]); first=0; } i = 2*i+1; }
    // Leaves
    for(i=n/2; i<n; i++) { if(arr[i] != -1) { if(!first) printf(" "); printf("%d", arr[i]); first=0; } }
    // Right boundary
    i = 2;
    int stack[100], top=-1;
    while(i < n) { if(arr[i] != -1) stack[++top] = arr[i]; i = 2*i+2; }
    while(top >= 0) { if(!first) printf(" "); printf("%d", stack[top--]); first=0; }
    printf("\n");
    return 0;
}
