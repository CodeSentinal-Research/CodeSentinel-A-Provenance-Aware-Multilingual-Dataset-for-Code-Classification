#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], count[2000001] = {0}, max_count = 0, res = 2000000000;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); count[arr[i]+1000000]++; }
    for(int i=0; i<n; i++) {
        int c = count[arr[i]+1000000];
        if(c > max_count || (c == max_count && arr[i] < res)) { max_count = c; res = arr[i]; }
    }
    printf("%d\n", res);
    return 0;
}
