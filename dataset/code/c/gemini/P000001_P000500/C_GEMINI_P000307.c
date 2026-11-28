#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_Q 2000
#define MAX_LEN 32

char queue[MAX_Q][MAX_LEN];
char visited[MAX_Q][MAX_LEN];
int q_front = 0, q_rear = 0, v_count = 0;

bool isValid(const char* s) {
    int cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt == 0;
}

bool isVisited(const char* s) {
    for (int i = 0; i < v_count; i++) {
        if (strcmp(visited[i], s) == 0) return true;
    }
    return false;
}

int main() {
    char s[MAX_LEN];
    if (scanf("%31s", s) == 1) {
        strcpy(queue[q_rear++], s);
        strcpy(visited[v_count++], s);
        bool found = false;
        while (q_front < q_rear) {
            int sz = q_rear - q_front;
            for (int i = 0; i < sz; i++) {
                char curr[MAX_LEN];
                strcpy(curr, queue[q_front++]);
                if (isValid(curr)) {
                    printf("%s\n", curr);
                    found = true;
                }
                if (!found) {
                    int len = strlen(curr);
                    for (int j = 0; j < len; j++) {
                        if (curr[j] == '(' || curr[j] == ')') {
                            char nextStr[MAX_LEN];
                            strncpy(nextStr, curr, j);
                            nextStr[j] = '\0';
                            strcat(nextStr, curr + j + 1);
                            if (!isVisited(nextStr) && v_count < MAX_Q && q_rear < MAX_Q) {
                                strcpy(visited[v_count++], nextStr);
                                strcpy(queue[q_rear++], nextStr);
                            }
                        }
                    }
                }
            }
            if (found) break;
        }
    }
    return 0;
}