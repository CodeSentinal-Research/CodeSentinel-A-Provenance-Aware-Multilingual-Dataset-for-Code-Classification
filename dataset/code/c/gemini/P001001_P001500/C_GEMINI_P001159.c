#include <string.h>

int numDecodings(char* s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
        int c = 0;
        if (s[i] != '0') c += b;
        int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two >= 10 && two <= 26) c += a;
        a = b;
        b = c;
    }
    return b;
}