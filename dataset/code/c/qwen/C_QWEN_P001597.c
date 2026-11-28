#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    int count[100001] = {0}; // assuming values in range
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int q; scanf("%d", &q);
    while(q--) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        int c = 0;
        for(int i=l; i<=r; i++) if(arr[i] == x) c++;
        printf("%d\n", c);
    }
    return 0;
}
