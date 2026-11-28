#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int last = vals[n-1];
    for(int i=0; i<n-1; i++) if(vals[i]<last) printf("%d ", vals[i]);
    printf("%d ", last);
    for(int i=0; i<n-1; i++) if(vals[i]>=last) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
