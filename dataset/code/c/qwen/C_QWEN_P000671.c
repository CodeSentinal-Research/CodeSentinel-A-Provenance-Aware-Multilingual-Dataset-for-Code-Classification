#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int sorted=1; for(int i=1; i<n; i++) if(vals[i]<vals[i-1]) { sorted=0; break; }
    printf("%s\n", sorted?"true":"false");
    return 0;
}
