#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int top[n], bot[n];
    for(int i=0; i<n; i++) scanf("%d", &top[i]);
    for(int i=0; i<n; i++) scanf("%d", &bot[i]);
    int count[7] = {0};
    for(int i=0; i<n; i++) { count[top[i]]++; count[bot[i]]++; }
    int max_count = 0, target = 0;
    for(int i=1; i<=6; i++) if(count[i] >= n && count[i] > max_count) { max_count = count[i]; target = i; }
    if(max_count < n) { printf("-1\n"); return 0; }
    int rot_top = 0, rot_bot = 0;
    for(int i=0; i<n; i++) {
        if(top[i] != target) rot_top++;
        if(bot[i] != target) rot_bot++;
    }
    printf("%d\n", rot_top < rot_bot ? rot_top : rot_bot);
    return 0;
}
