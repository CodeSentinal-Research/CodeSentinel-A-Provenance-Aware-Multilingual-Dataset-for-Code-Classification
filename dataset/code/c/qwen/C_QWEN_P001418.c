#include <stdio.h>
#include <string.h>

int main() {
    char allowed[27];
    scanf("%s", allowed);
    int n;
    scanf("%d", &n);
    
    int present[256] = {0};
    for (int i = 0; allowed[i]; i++) present[allowed[i]] = 1;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        char word[101];
        scanf("%s", word);
        int consistent = 1;
        for (int j = 0; word[j]; j++) {
            if (!present[word[j]]) {
                consistent = 0;
                break;
            }
        }
        if (consistent) count++;
    }
    printf("%d\n", count);
    return 0;
}
