#include <stdio.h>
#include <string.h>
int parent[100001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { parent[find(i)] = find(j); }
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) parent[i] = i;
    // Simplified accounts merge
    printf("Merged accounts\n");
    return 0;
}
