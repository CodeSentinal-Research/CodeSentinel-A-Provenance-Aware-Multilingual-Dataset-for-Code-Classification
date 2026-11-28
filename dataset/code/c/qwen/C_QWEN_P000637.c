#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n; i++) {
        int dup=0;
        for(int j=0; j<n; j++) if(i!=j && vals[i]==vals[j]) { dup=1; break; }
        if(!dup) printf("%d ", vals[i]);
    }
    printf("\n");
    return 0;
}
