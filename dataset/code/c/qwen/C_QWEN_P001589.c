#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0;
    int prefix[n+1]; prefix[0] = 0;
    int first_seen[2*n+1];
    for(int i=0; i<=2*n; i++) first_seen[i] = -2;
    first_seen[n] = 0;
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + (arr[i] > 8 ? 1 : -1);
        int val = prefix[i+1] - 1;
        if(first_seen[val + n] != -2) {
            if(i + 1 - first_seen[val + n] > max_len) max_len = i + 1 - first_seen[val + n];
        }
        if(first_seen[prefix[i+1] + n] == -2) first_seen[prefix[i+1] + n] = i + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
