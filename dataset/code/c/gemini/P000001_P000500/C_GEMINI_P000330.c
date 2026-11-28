#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_W 100
char words[MAX_W][105];
int w_count = 0;

int main() {
    char s[505];
    if (scanf("%504s", s) == 1) {
        while (scanf("%104s", words[w_count]) == 1) {
            w_count++;
            if (w_count >= MAX_W) break;
        }
        int n = strlen(s);
        bool bold[505] = {false};
        for (int k = 0; k < w_count; k++) {
            int wlen = strlen(words[k]);
            char* ptr = strstr(s, words[k]);
            while (ptr != NULL) {
                int pos = ptr - s;
                for (int i = pos; i < pos + wlen; i++) bold[i] = true;
                ptr = strstr(s + pos + 1, words[k]);
            }
        }
        for (int i = 0; i < n; ) {
            if (bold[i]) {
                printf("<b>");
                while (i < n && bold[i]) {
                    putchar(s[i++]);
                }
                printf("</b>");
            } else {
                putchar(s[i++]);
            }
        }
        printf("\n");
    }
    return 0;
}