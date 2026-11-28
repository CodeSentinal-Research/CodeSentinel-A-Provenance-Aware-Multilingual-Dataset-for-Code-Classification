#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]==0 && (i==0 || arr[i-1]==0) && (i==n-1 || arr[i+1]==0)) { arr[i]=1; count++; }
    }
    printf("%s\n", count >= m ? "Yes" : "No");
    return 0;
}
