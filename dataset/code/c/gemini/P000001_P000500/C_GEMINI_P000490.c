#include <stdio.h>
#include <string.h>
#define MAX_N 10005
void process(char* in, char* out) {
    int top = 0;
    for (int i = 0; in[i]; i++) {
        if (in[i] == '#') {
            if (top > 0) top--;
        } else {
            out[top++] = in[i];
        }
    }
    out[top] = '\0';
}
int main() {
    char s[MAX_N], t[MAX_N];
    if (scanf("%10004s", s) >= 1) {
        if (scanf("%10004s", t) != 1) t[0] = '\0';
        char res_s[MAX_N], res_t[MAX_N];
        process(s, res_s);
        process(t, res_t);
        printf("%s\n", strcmp(res_s, res_t) == 0 ? "true" : "false");
    }
    return 0;
}