#include <stdio.h>
#include <string.h>
int memo[61];
int canWin(char *s) {
    if(memo[(int)(long long)s] != -1) return memo[(int)(long long)s]; // simplified
    for(int i=0; s[i+1]; i++) {
        if(s[i] == '+' && s[i+1] == '+') {
            s[i] = '-'; s[i+1] = '-';
            int res = !canWin(s);
            s[i] = '+'; s[i+1] = '+';
            if(res) return 1;
        }
    }
    return 0;
}
int main() {
    char s[61]; scanf("%s", s);
    printf("%s\n", canWin(s) ? "true" : "false");
    return 0;
}
