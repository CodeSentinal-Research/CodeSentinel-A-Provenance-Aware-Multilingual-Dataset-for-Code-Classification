#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int even[n], odd[n], e=0, o=0;
    for(int i=0; i<n; i++) { if(vals[i]%2==0) even[e++]=vals[i]; else odd[o++]=vals[i]; }
    for(int i=0; i<e; i++) printf("%d ", even[i]);
    for(int i=0; i<o; i++) printf("%d ", odd[i]);
    printf("\n");
    return 0;
}
