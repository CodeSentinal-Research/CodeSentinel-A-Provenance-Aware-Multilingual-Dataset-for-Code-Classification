#include <stdio.h>
int main() {
    int n, q; scanf("%d", &n);
    int arr[10000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &q);
    while(q--) {
        int x; scanf("%d", &x);
        int found = 0;
        for(int i=0; i<n; i++) if(arr[i]==x) { found=1; break; }
        printf("%s\n", found ? "Found" : "Not Found");
    }
    return 0;
}
