#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], prefix[n+1];
    prefix[0] = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); prefix[i+1] = prefix[i] + (arr[i] % 2 == 0 ? 1 : 0); }
    int q; scanf("%d", &q);
    while(q--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", prefix[r+1] - prefix[l]);
    }
    return 0;
}
