#include <stdio.h>
int main() {
    int n, val; scanf("%d %d", &n, &val);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int j=0;
    for(int i=0; i<n; i++) if(vals[i]!=val) vals[j++]=vals[i];
    for(int i=0; i<j; i++) printf("%d%c", vals[i], i==j-1?'\n':' ');
    printf("\n");
    return 0;
}
