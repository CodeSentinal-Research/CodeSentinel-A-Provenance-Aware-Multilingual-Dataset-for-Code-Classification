#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 10005
int nums[MAX_N];
char ops[MAX_N][16];
int main() {
    char token[256];
    int num_count = 0, op_count = 0;
    while (scanf("%255s", token) == 1) {
        if (strcmp(token, "next()") == 0 || strcmp(token, "hasNext()") == 0) {
            strcpy(ops[op_count++], token);
        } else {
            int i = 0;
            while (token[i]) {
                if (isdigit(token[i]) || (token[i] == '-' && isdigit(token[i+1]))) {
                    int sign = 1;
                    if (token[i] == '-') { sign = -1; i++; }
                    int val = 0;
                    while (token[i] && isdigit(token[i])) {
                        val = val * 10 + (token[i] - '0');
                        i++;
                    }
                    nums[num_count++] = sign * val;
                } else {
                    i++;
                }
            }
        }
    }
    int idx = 0;
    for (int i = 0; i < op_count; i++) {
        if (strcmp(ops[i], "next()") == 0) {
            if (idx < num_count) printf("%d\n", nums[idx++]);
        } else {
            printf("%s\n", idx < num_count ? "true" : "false");
        }
    }
    return 0;
}