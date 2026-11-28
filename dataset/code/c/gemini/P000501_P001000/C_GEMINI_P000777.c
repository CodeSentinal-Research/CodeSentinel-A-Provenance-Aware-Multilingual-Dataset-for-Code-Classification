#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char grid[32][32];
char words[32][32];
int n, w_cnt;
bool can_place_h(int r, int c, char* w) {
    int len = strlen(w);
    if (c + len > n) return false;
    for (int i = 0; i < len; i++) {
        if (grid[r][c + i] != '-' && grid[r][c + i] != w[i]) return false;
    }
    return true;
}
int place_h(int r, int c, char* w, int pr[], int pc[]) {
    int len = strlen(w), count = 0;
    for (int i = 0; i < len; i++) {
        if (grid[r][c + i] == '-') {
            grid[r][c + i] = w[i];
            pr[count] = r; pc[count] = c + i; count++;
        }
    }
    return count;
}
bool can_place_v(int r, int c, char* w) {
    int len = strlen(w);
    if (r + len > n) return false;
    for (int i = 0; i < len; i++) {
        if (grid[r + i][c] != '-' && grid[r + i][c] != w[i]) return false;
    }
    return true;
}
int place_v(int r, int c, char* w, int pr[], int pc[]) {
    int len = strlen(w), count = 0;
    for (int i = 0; i < len; i++) {
        if (grid[r + i][c] == '-') {
            grid[r + i][c] = w[i];
            pr[count] = r + i; pc[count] = c; count++;
        }
    }
    return count;
}
void unplace(int count, int pr[], int pc[]) {
    for (int i = 0; i < count; i++) grid[pr[i]][pc[i]] = '-';
}
bool backtrack(int idx) {
    if (idx == w_cnt) return true;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (can_place_h(r, c, words[idx])) {
                int pr[32], pc[32];
                int count = place_h(r, c, words[idx], pr, pc);
                if (backtrack(idx + 1)) return true;
                unplace(count, pr, pc);
            }
            if (can_place_v(r, c, words[idx])) {
                int pr[32], pc[32];
                int count = place_v(r, c, words[idx], pr, pc);
                if (backtrack(idx + 1)) return true;
                unplace(count, pr, pc);
            }
        }
    }
    return false;
}
int main() {
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%31s", grid[i]);
        scanf("%d", &w_cnt);
        for (int i = 0; i < w_cnt; i++) scanf("%31s", words[i]);
        backtrack(0);
        for (int i = 0; i < n; i++) printf("%s\n", grid[i]);
    }
    return 0;
}