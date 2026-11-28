#include <stdio.h>
#include <string.h>
int memo[1 << 21];
int canWin(int max, int total, int used, int turn_total) {
    if(turn_total >= total) return 0;
    if(memo[used] != -1) return memo[used];
    for(int i=1; i<=max; i++) {
        if(!(used & (1 << i))) {
            if(!canWin(max, total, used | (1 << i), turn_total + i)) return memo[used] = 1;
        }
    }
    return memo[used] = 0;
}
int main() {
    int max, total; scanf("%d%d", &max, &total);
    memset(memo, -1, sizeof(memo));
    printf("%s\n", canWin(max, total, 0, 0) ? "true" : "false");
    return 0;
}
