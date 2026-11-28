#include <stdio.h>
int main() {
    int n, m1, m2; scanf("%d%d%d", &n, &m1, &m2);
    int deg1[n], deg2[n];
    for(int i=0; i<n; i++) deg1[i] = 0;
    for(int i=0; i<n; i++) deg2[i] = 0;
    for(int i=0; i<m1; i++) { int u, v; scanf("%d%d", &u, &v); deg1[u-1]++; deg1[v-1]++; }
    for(int i=0; i<m2; i++) { int u, v; scanf("%d%d", &u, &v); deg2[u-1]++; deg2[v-1]++; }
    int same = 1;
    for(int i=0; i<n; i++) if(deg1[i] != deg2[i]) same = 0;
    printf("%s\n", same ? "YES" : "NO");
    return 0;
}
