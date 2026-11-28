#include <stdio.h>
#include <string.h>
char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void gen(char *digits, int idx, char *curr, int c_idx) {
    if(digits[idx]=='\0') { curr[c_idx]='\0'; printf("%s\n", curr); return; }
    int d = digits[idx]-'0';
    for(int i=0; map[d][i]; i++) { curr[c_idx]=map[d][i]; gen(digits, idx+1, curr, c_idx+1); }
}
int main() {
    char digits[5]; scanf("%s", digits);
    char curr[10];
    gen(digits, 0, curr, 0);
    return 0;
}
