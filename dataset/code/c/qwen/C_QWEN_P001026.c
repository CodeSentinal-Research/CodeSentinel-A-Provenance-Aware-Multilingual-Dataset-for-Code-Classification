#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int parent[n]; for(int i=0; i<n; i++) scanf("%d", &parent[i]);
    int count[n]; for(int i=0; i<n; i++) count[i] = 0;
    for(int i=0; i<n; i++) if(parent[i] != -1) count[parent[i]]++;
    int ok = 1;
    for(int i=0; i<n; i++) if(count[i] > 2) ok = 0;
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
