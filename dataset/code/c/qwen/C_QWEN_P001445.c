#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int si = 0, wi = 0;
        while (s[si] && words[i][wi]) {
            if (s[si] == words[i][wi]) wi++;
            si++;
        }
        if (words[i][wi] == '\0') count++;
    }
    printf("%d\n", count);
    return 0;
}
