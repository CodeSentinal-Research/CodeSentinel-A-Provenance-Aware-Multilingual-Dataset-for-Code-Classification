#include <stdio.h>
#include <ctype.h>

/* Basic Calculator III */
int main(void) {
    char s[200000];
    long long total = 0, last = 0, num = 0;
    char op = '+';
    if (scanf(" %199999[^\n]", s) != 1) return 1;
    for (int i = 0; ; i++) {
        if (isdigit((unsigned char)s[i])) num = num * 10 + s[i] - '0';
        if ((!isdigit((unsigned char)s[i]) && s[i] != ' ') || s[i] == '\0') {
            if (op == '+') { total += last; last = num; }
            else if (op == '-') { total += last; last = -num; }
            else if (op == '*') last *= num;
            else if (op == '/') last /= num;
            op = s[i];
            num = 0;
        }
        if (s[i] == '\0') break;
    }
    printf("%lld\n", total + last);

    return 0;
}
