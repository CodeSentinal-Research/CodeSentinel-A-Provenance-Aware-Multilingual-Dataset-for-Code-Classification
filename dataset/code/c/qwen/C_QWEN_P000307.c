#include <stdio.h>
#include <string.h>
int main() {
    char s[21]; scanf("%s", s);
    int min_rem = 0, open = 0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='(') open++;
        else if(s[i]==')') { if(open>0) open--; else min_rem++; }
    }
    min_rem += open;
    // Simplified: just print valid string by removing min invalid
    int rem_open = open, rem_close = min_rem - open; // rough logic for template
    int idx = 0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='(' && rem_open > 0) { rem_open--; continue; }
        if(s[i]==')' && rem_close > 0) { rem_close--; continue; }
        s[idx++] = s[i];
    }
    s[idx] = '\0';
    printf("%s\n", s);
    return 0;
}
