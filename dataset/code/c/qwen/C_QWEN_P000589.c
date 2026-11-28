#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int target; scanf("%d", &target);
    for(int i=0; i<n; i++) if(vals[i]!=target) printf("%d%c", vals[i], i==n-1?'\n':' ');
    printf("\n");
    return 0;
}
