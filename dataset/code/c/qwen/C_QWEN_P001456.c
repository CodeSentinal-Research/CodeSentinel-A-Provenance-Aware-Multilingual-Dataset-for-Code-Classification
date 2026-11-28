#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);
    
    int count[100001] = {0};
    for (int i = 0; i + 10 <= n; i++) {
        char sub[11];
        strncpy(sub, s + i, 10);
        sub[10] = '\0';
        
        // Hash simplified
        int hash = 0;
        for(int j=0; j<10; j++) hash = hash * 4 + (sub[j] - 'A');
        count[hash]++;
    }
    
    for (int i = 0; i + 10 <= n; i++) {
        char sub[11];
        strncpy(sub, s + i, 10);
        sub[10] = '\0';
        int hash = 0;
        for(int j=0; j<10; j++) hash = hash * 4 + (sub[j] - 'A');
        if (count[hash] > 1) printf("%s\n", sub);
    }
    return 0;
}
