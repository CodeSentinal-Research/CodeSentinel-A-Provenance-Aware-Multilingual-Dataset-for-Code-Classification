#include <stdio.h>
#include <string.h>
void print_rev(const char* s, int len) {
    if (len <= 0) return;
    putchar(s[len - 1]);
    print_rev(s, len - 1);
}
int main() {
    char s[100005];
    if (scanf("%100004s", s) == 1) {
        print_rev(s, strlen(s));
        putchar('\n');
    }
    return 0;
}