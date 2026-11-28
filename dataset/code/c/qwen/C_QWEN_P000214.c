#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); int idx = arr[i]<0 ? -arr[i]-1 : arr[i]-1; if(arr[idx]>0) arr[idx]=-arr[idx]; }
    int first = 1;
    for(int i=0; i<n; i++) if(arr[i]>0) { if(!first) printf(" "); printf("%d", i+1); first=0; }
    printf("\n");
    return 0;
}
