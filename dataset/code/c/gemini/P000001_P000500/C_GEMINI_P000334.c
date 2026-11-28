#include <stdio.h>
#include <string.h>

int shortestWay(const char* source, const char* target) {
    int i = 0, count = 0;
    int tlen = strlen(target), slen = strlen(source);
    while (i < tlen) {
        int initial_i = i;
        for (int j = 0; j < slen; j++) {
            if (i < tlen && source[j] == target[i]) {
                i++;
            }
        }
        if (i == initial_i) return -1;
        count++;
    }
    return count;
}

int main() {
    char s[1005], t[1005];
    if (scanf("%1004s %1004s", s, t) == 2) {
        printf("%d\n", shortestWay(s, t));
    }
    return 0;
}