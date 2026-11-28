#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkRecord(const char* s) {
    int a_cnt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            a_cnt++;
            if (a_cnt >= 2) return false;
        }
    }
    return strstr(s, "LLL") == NULL;
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        printf("%s\n", checkRecord(s) ? "Yes" : "No");
    }
    return 0;
}