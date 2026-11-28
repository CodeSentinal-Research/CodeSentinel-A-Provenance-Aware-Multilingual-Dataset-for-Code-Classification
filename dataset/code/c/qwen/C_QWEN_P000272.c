#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char strs[100][201];
    for(int i=0; i<n; i++) scanf("%s", strs[i]);
    int min_len = strlen(strs[0]);
    for(int i=1; i<n; i++) if(strlen(strs[i]) < min_len) min_len = strlen(strs[i]);
    int lcp=0;
    for(int i=0; i<min_len; i++) {
        char c = strs[0][i]; int match=1;
        for(int j=1; j<n; j++) if(strs[j][i] != c) { match=0; break; }
        if(!match) break;
        lcp++;
    }
    char res[201]; strncpy(res, strs[0], lcp); res[lcp]='\0';
    printf("%s\n", res);
    return 0;
}
