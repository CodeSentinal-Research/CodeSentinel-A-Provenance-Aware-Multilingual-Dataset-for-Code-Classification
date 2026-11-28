#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[200001];
    fgets(s, 200001, stdin);
    if (s[strlen(s)-1] == '\n') s[strlen(s)-1] = '\0';
    
    int l = 0, r = strlen(s) - 1;
    int pal = 1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) { pal = 0; break; }
        l++; r--;
    }
    printf("%s\n", pal ? "YES" : "NO");
    return 0;
}
