#include <stdio.h>
int parent[2001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { parent[find(i)] = find(j); }
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) parent[i] = i;
    int count = n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        int x; scanf("%d", &x);
        if(x && find(i) != find(j)) { unite(i, j); count--; }
    }
    printf("%d\n", count);
    return 0;
}
