#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, pos_len = 0, neg_len = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) { pos_len++; neg_len = neg_len > 0 ? neg_len + 1 : 0; }
        else if(arr[i] < 0) {
            int t = pos_len;
            pos_len = neg_len > 0 ? neg_len + 1 : 0;
            neg_len = t + 1;
        } else { pos_len = 0; neg_len = 0; }
        if(pos_len > max_len) max_len = pos_len;
    }
    printf("%d\n", max_len);
    return 0;
}
