#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int level = 0, count = 1, start = 0;
    while(start < n) {
        for(int i=start; i<start+count && i<n; i++) printf("%d%c", a[i], i==start+count-1 || i==n-1?'\n':' ');
        start += count;
        count *= 2;
        level++;
    }
    return 0;
}
