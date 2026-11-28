#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m); int a[n], b[m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    if(n!=m) printf("false\n");
    else { int eq=1; for(int i=0; i<n; i++) if(a[i]!=b[i]) { eq=0; break; } printf("%s\n", eq?"true":"false"); }
    return 0;
}
