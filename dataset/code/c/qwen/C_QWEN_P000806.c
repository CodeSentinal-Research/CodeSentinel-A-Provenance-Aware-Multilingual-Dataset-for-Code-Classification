#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n); int a[n], prefix[n+1]; prefix[0]=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); prefix[i+1] = prefix[i] + (a[i]>0?1:-1); }
    int first[200001]; memset(first, -2, sizeof(first));
    first[100000] = 0; int max_len = 0;
    for(int i=1; i<=n; i++) {
        if(first[prefix[i]+100000] != -2) {
            if(i - first[prefix[i]+100000] > max_len) max_len = i - first[prefix[i]+100000];
        } else first[prefix[i]+100000] = i;
    }
    printf("%d\n", max_len);
    return 0;
}
