#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int mid = n/2;
    for(int i=0; i<n; i++) if(i!=mid) printf("%d ", vals[i]);
    printf("\n");
    return 0;
}
