#include <stdio.h>
#include <string.h>
int main() {
    char w1[9], w2[9], tw[9]; scanf("%s %s %s", w1, w2, tw);
    long long v(char *s) { long long v=0; for(int i=0; s[i]; i++) v = v*10 + (s[i]-'a'); return v; }
    printf("%s\n", v(w1)+v(w2)==v(tw) ? "Yes" : "No");
    return 0;
}
