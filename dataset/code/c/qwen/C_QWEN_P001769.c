#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int val[n]; for(int i=0; i<n; i++) scanf("%d", &val[i]);
    int min_val = val[0];
    for(int i=1; i<n; i++) if(val[i] < min_val) min_val = val[i];
    printf("%d\n", min_val);
    return 0;
}
