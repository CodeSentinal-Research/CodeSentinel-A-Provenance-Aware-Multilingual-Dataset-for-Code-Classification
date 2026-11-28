#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int count[200001] = {0};
    for(int i=0; i<n; i++) count[a[i]]++;
    int start = a[0], len = 0;
    for(int i=0; i<n; i++) {
        if(count[a[i]] > 0) {
            int curr = a[i], curr_len = 0;
            while(count[curr] > 0) { count[curr]--; curr++; curr_len++; }
            if(curr_len >= 3 && curr_len > len) { len = curr_len; start = a[i]; }
        }
    }
    printf("%s\n", len >= 3 ? "YES" : "NO");
    return 0;
}
