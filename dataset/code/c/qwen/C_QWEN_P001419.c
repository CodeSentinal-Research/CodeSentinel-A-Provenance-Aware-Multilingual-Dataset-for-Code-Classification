#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[200001];
    scanf("%s", s);
    
    int count[256] = {0};
    for (int i = 0; s[i]; i++) count[s[i]]++;
    
    int freq[200001] = {0};
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) freq[count[i]]++;
    }
    
    // Sort by frequency descending, then lexicographically
    char res[200001];
    int idx = 0;
    for (int f = 200000; f >= 1; f--) {
        if (freq[f] > 0) {
            for (int i = 0; i < 256; i++) {
                if (count[i] == f) {
                    for (int j = 0; j < f; j++) res[idx++] = i;
                }
            }
        }
    }
    res[idx] = '\0';
    printf("%s\n", res);
    return 0;
}
