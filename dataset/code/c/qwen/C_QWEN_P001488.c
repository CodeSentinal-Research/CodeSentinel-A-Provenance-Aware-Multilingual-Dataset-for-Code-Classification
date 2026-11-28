#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    int l = 0, r = n - 1;
    while (l < r && s[l] == s[r]) {
        char c = s[l];
        while (l <= r && s[l] == c) l++;
        while (l <= r && s[r] == c) r--;
    }
    printf("%d\n", r - l + 1 < 0 ? 0 : r - l + 1);
    return 0;
}
