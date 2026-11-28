#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int pre[n];
    for(int i=0; i<n; i++) scanf("%d", &pre[i]);
    int ok = 1;
    for(int i=0; i<n-1; i++) {
        if(pre[i] < pre[i+1]) {
            int found = 0;
            for(int j=i+2; j<n; j++) if(pre[j] > pre[i] && pre[j] < pre[i+1]) { found=1; break; }
            if(!found) { ok=0; break; }
        }
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
