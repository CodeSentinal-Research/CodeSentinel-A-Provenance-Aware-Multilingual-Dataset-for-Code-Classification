#include <stdio.h>
#include <string.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    if(n % k != 0) { printf("NO\n"); return 0; }
    int count[100001] = {0};
    for(int i=0; i<n; i++) count[a[i]]++;
    int start = 0;
    for(int i=0; i<=100000; i++) {
        while(count[i] > 0) {
            if(i - start + 1 > k) { printf("NO\n"); return 0; }
            count[i]--;
            start = i + 1;
        }
    }
    printf("YES\n");
    return 0;
}
