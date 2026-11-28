#include <stdio.h>
#include <string.h>
int val(char c) {
    if(c=='I') return 1; if(c=='V') return 5; if(c=='X') return 10;
    if(c=='L') return 50; if(c=='C') return 100; if(c=='D') return 500; if(c=='M') return 1000;
    return 0;
}
int main() {
    char s[16]; scanf("%s", s);
    int res=0;
    for(int i=0; s[i]; i++) {
        if(s[i+1] && val(s[i]) < val(s[i+1])) res -= val(s[i]);
        else res += val(s[i]);
    }
    printf("%d\n", res);
    return 0;
}
