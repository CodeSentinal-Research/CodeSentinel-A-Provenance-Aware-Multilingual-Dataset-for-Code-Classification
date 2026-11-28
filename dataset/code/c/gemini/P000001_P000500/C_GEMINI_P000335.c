#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_Q 200
char queries[MAX_Q][105];
int q_cnt = 0;

int main() {
    while (scanf("%104s", queries[q_cnt]) == 1) {
        q_cnt++;
        if (q_cnt >= MAX_Q) break;
    }
    if (q_cnt >= 2) {
        char* pattern = queries[q_cnt - 1];
        int plen = strlen(pattern);
        for (int k = 0; k < q_cnt - 1; k++) {
            char* q = queries[k];
            int qlen = strlen(q);
            int i = 0;
            bool ok = true;
            for (int j = 0; j < qlen; j++) {
                if (i < plen && q[j] == pattern[i]) {
                    i++;
                } else if (isupper(q[j])) {
                    ok = false;
                    break;
                }
            }
            printf("%s\n", (ok && i == plen) ? "true" : "false");
        }
    }
    return 0;
}