#include <stdio.h>
#include <string.h>
int main() {
    int r; scanf("%d", &r);
    int routes[r][100], sizes[r];
    for(int i=0; i<r; i++) {
        scanf("%d", &sizes[i]);
        for(int j=0; j<sizes[i]; j++) scanf("%d", &routes[i][j]);
    }
    int src, tgt; scanf("%d %d", &src, &tgt);
    if(src==tgt) { printf("0\n"); return 0; }
    int queue[100001], front=0, rear=0, visited_routes[501]={0}, visited_stops[1000001]={0};
    for(int i=0; i<r; i++) {
        for(int j=0; j<sizes[i]; j++) {
            if(routes[i][j]==src) { queue[rear++]=i; visited_routes[i]=1; visited_stops[src]=1; break; }
        }
    }
    int buses=1;
    while(front<rear) {
        int size=rear-front;
        for(int k=0; k<size; k++) {
            int route=queue[front++];
            for(int j=0; j<sizes[route]; j++) {
                int stop=routes[route][j];
                if(stop==tgt) { printf("%d\n", buses); return 0; }
                for(int i=0; i<r; i++) {
                    if(!visited_routes[i]) {
                        for(int l=0; l<sizes[i]; l++) {
                            if(routes[i][l]==stop) { queue[rear++]=i; visited_routes[i]=1; break; }
                        }
                    }
                }
            }
        }
        buses++;
    }
    printf("-1\n");
    return 0;
}
