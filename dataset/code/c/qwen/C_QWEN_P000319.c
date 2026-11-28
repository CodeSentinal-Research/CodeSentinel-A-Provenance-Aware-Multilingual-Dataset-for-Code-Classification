#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], t[1001]; scanf("%s %s", s, t);
    int ls = strlen(s), lt = strlen(t);
    if(abs(ls-lt) > 1) { printf("No\n"); return 0; }
    int i=0, j=0, diff=0;
    while(i<ls && j<lt) {
        if(s[i] != t[j]) {
            diff++;
            if(ls > lt) i++;
            else if(lt > ls) j++;
            else { i++; j++; }
        } else { i++; j++; }
        if(diff > 1) { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    return 0;
}
