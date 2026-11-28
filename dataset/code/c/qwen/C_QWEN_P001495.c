#include <stdio.h>
#include <string.h>

int main() {
    char s[200001], t[200001];
    scanf("%s %s", s, t);
    
    int i = 0, j = 0;
    while (i < strlen(s) && j < strlen(t)) {
        if (s[i] == t[j]) j++;
        i++;
    }
    printf("%d\n", strlen(t) - j);
    return 0;
}
