#include <stdio.h>

int main() {
    char n[20];
    scanf("%s", n);
    int d = 0, f = 1;
    if (n[0] == '0') f = 0;
    for (int i = 0; n[i]; i++) if (n[i] == '0') d = 1;
    printf("%s\n", (d && f) ? "Duck" : "Not Duck");
    return 0;
}
