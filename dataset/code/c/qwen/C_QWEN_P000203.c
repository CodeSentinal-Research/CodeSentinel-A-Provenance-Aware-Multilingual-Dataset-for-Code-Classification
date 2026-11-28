#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n], count[1001] = {0};
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); count[arr[i]]++; }
    int max_rep = 0, res = 0;
    for(int i=0; i<k; i++) if(count[i] > max_rep) { max_rep = count[i]; res = i; }
    printf("%d\n", res);
    return 0;
}
