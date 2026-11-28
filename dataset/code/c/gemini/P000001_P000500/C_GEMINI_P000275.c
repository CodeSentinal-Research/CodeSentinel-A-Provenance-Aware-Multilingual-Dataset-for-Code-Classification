#include <stdio.h>

int compress(char* chars, int charsSize) {
    int write = 0, read = 0;

    while (read < charsSize) {
        char ch = chars[read];
        int count = 0;
        while (read < charsSize && chars[read] == ch) {
            read++;
            count++;
        }

        chars[write++] = ch;

        if (count > 1) {
            char buf[16];
            int len = sprintf(buf, "%d", count);
            for (int i = 0; i < len; i++) {
                chars[write++] = buf[i];
            }
        }
    }
    return write;
}