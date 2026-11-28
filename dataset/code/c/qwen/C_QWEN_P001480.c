#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    
    int last[256] = {0};
    for (int i = 0; s[i]; i++) last[s[i]] = i;
    
    int start = 0, end = 0;
    for (int i = 0; s[i]; i++) {
        if (last[s[i]] > end) end = last[s[i]];
        if (i == end) {
            printf("%d ", end - start + 1);
            start = i + 1;
        }
    }
    printf("\n");
    return 0;
}
