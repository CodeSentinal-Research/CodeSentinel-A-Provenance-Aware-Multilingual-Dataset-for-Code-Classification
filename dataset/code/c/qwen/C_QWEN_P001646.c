#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int first = 1;
    int i = 0;
    while(i < n) {
        if(arr[i] != -1) { if(!first) printf(" "); printf("%d", arr[i]); first=0; }
        i = 2*i+1; // simplified left-most logic
    }
    printf("\n");
    return 0;
}
