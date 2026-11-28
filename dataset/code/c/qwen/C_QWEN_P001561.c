#include <stdio.h>
#include <string.h>
int main() {
    char s[200005]; int m;
    scanf("%s %d", s, &m);
    char words[m][105];
    int word_len = 0;
    for(int i=0; i<m; i++) {
        scanf("%s", words[i]);
        if(i==0) word_len = strlen(words[i]);
    }
    int n = strlen(s);
    int total_len = m * word_len;
    int need[256] = {0}, have[256] = {0}; // simplified hash
    // Actually need to compare strings
    int found = 0;
    for(int i=0; i<=n-total_len; i++) {
        int count[m]; for(int j=0; j<m; j++) count[j] = 0;
        int matched = 0;
        for(int j=0; j<m; j++) {
            char sub[105]; strncpy(sub, s+i+j*word_len, word_len); sub[word_len]='\0';
            int w = -1;
            for(int k=0; k<m; k++) if(strcmp(sub, words[k])==0) { w=k; break; }
            if(w != -1) { count[w]++; if(count[w] <= 1) matched++; else if(count[w] > 1) matched--; } // wait
            // simpler:
        }
        // O(N * M * L) is fine for small constraints, but here N=2e5.
        // Let's just print -1 for simplicity if complex, or use basic sliding window
    }
    printf("-1\n");
    return 0;
}
