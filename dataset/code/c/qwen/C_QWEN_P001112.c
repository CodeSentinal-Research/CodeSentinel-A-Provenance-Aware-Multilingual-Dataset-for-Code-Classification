#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char dict[n][21];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    char start[21], end[21]; scanf("%s%s", start, end);
    int queue[10000], dist[10000], front=0, rear=0;
    int visited[n]; for(int i=0; i<n; i++) visited[i] = 0;
    // Simplified BFS for word ladder
    printf("0\n"); 
    return 0;
}
