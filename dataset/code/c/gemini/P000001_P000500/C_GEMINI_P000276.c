#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* countAndSay(int n) {
    char* s = (char*)malloc(10005 * sizeof(char));
    strcpy(s, "1");

    for (int step = 1; step < n; step++) {
        char nextS[10005] = "";
        int len = strlen(s);
        int i = 0;

        while (i < len) {
            int count = 1;
            while (i + 1 < len && s[i] == s[i + 1]) {
                i++;
                count++;
            }
            char buf[16];
            sprintf(buf, "%d%c", count, s[i]);
            strcat(nextS, buf);
            i++;
        }
        strcpy(s, nextS);
    }
    return s;
}