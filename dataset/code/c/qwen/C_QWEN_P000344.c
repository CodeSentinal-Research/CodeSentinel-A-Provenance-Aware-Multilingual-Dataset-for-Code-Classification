#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char words[1000][11], s[11];
    for(int i=0; i<n; i++) scanf("%s", words[i]);
    scanf("%s", s);
    int count = 0;
    for(int i=0; i<n; i++) {
        if(strncmp(s, words[i], strlen(words[i])) == 0) count++;
    }
    printf("%d\n", count);
    return 0;
}
