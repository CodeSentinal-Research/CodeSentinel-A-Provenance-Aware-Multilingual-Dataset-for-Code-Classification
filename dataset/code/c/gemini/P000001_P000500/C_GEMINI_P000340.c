#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char text[1005], broken[32];
    if (fgets(text, sizeof(text), stdin) && fgets(broken, sizeof(broken), stdin)) {
        bool b[256] = {false};
        for (int i = 0; broken[i] && broken[i] != '\n' && broken[i] != '\r'; i++) {
            b[(unsigned char)broken[i]] = true;
        }
        int count = 0;
        char* token = strtok(text, " \t\r\n");
        while (token) {
            bool ok = true;
            for (int i = 0; token[i]; i++) {
                if (b[(unsigned char)token[i]]) { ok = false; break; }
            }
            if (ok) count++;
            token = strtok(NULL, " \t\r\n");
        }
        printf("%d\n", count);
    }
    return 0;
}