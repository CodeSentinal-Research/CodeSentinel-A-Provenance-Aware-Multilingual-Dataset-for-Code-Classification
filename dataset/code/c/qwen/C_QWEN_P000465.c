#include <stdio.h>
int main() {
    int n, diff; scanf("%d %d", &n, &diff);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int found = 0;
    for(int i=0; i<n && !found; i++)
        for(int j=i+1; j<n && !found; j++)
            if(arr[j]-arr[i]==diff || arr[i]-arr[j]==diff) found=1;
    printf("%s\n", found ? "Yes" : "No");
    return 0;
}
