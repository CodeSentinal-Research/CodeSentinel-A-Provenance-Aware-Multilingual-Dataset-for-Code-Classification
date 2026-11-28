#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_R 505
#define MAX_STOPS 1005
int routes[MAX_R][MAX_STOPS];
int route_len[MAX_R];
bool vis_routes[MAX_R];
int q_stop[100005], q_buses[100005];
int main() {
    int r;
    if (scanf("%d", &r) == 1) {
        for (int i = 0; i < r; i++) {
            scanf("%d", &route_len[i]);
            for (int j = 0; j < route_len[i]; j++) {
                scanf("%d", &routes[i][j]);
            }
        }
        int source, target;
        scanf("%d %d", &source, &target);
        if (source == target) { printf("0\n"); return 0; }
        memset(vis_routes, 0, sizeof(vis_routes));
        int head = 0, tail = 0;
        q_stop[tail] = source; q_buses[tail++] = 0;
        int ans = -1;
        while (head < tail) {
            int stop = q_stop[head];
            int buses = q_buses[head++];
            for (int i = 0; i < r; i++) {
                if (vis_routes[i]) continue;
                bool has_stop = false;
                for (int j = 0; j < route_len[i]; j++) {
                    if (routes[i][j] == stop) { has_stop = true; break; }
                }
                if (has_stop) {
                    vis_routes[i] = true;
                    for (int j = 0; j < route_len[i]; j++) {
                        if (routes[i][j] == target) { ans = buses + 1; break; }
                        q_stop[tail] = routes[i][j];
                        q_buses[tail++] = buses + 1;
                    }
                }
                if (ans != -1) break;
            }
            if (ans != -1) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}