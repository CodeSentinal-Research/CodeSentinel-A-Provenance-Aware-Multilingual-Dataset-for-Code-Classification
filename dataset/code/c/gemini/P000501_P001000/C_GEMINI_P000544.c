#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NODES 10000
bool visited[MAX_NODES];
int q_nodes[MAX_NODES];
int q_dist[MAX_NODES];
int to_num(const char* s) {
    return (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
}
int main() {
    int d;
    if (scanf("%d", &d) == 1) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < d; i++) {
            char s[8]; scanf("%7s", s);
            visited[to_num(s)] = true;
        }
        char target_s[8]; scanf("%7s", target_s);
        int target = to_num(target_s);
        if (visited[0]) { printf("-1\n"); return 0; }
        if (target == 0) { printf("0\n"); return 0; }
        int head = 0, tail = 0;
        q_nodes[tail] = 0; q_dist[tail++] = 0;
        visited[0] = true;
        int ans = -1;
        while (head < tail) {
            int cur = q_nodes[head];
            int dist = q_dist[head++];
            if (cur == target) { ans = dist; break; }
            int digits[4] = {cur / 1000, (cur / 100) % 10, (cur / 10) % 10, cur % 10};
            int mult[4] = {1000, 100, 10, 1};
            for (int i = 0; i < 4; i++) {
                for (int diff = -1; diff <= 1; diff += 2) {
                    int nd = (digits[i] + diff + 10) % 10;
                    int nxt = cur - digits[i] * mult[i] + nd * mult[i];
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q_nodes[tail] = nxt;
                        q_dist[tail++] = dist + 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}