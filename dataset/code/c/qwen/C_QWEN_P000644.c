#include <stdio.h>
int main() {
    int n, x, y; scanf("%d %d %d", &n, &x, &y); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) { if(vals[i]==x) vals[i]=y; else if(vals[i]==y) vals[i]=x; }
    for(int i=0; i<n; i++) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
