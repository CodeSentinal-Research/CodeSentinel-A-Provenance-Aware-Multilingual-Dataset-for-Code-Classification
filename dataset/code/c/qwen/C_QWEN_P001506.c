#include <stdio.h>
#include <string.h>
int main() {
    char s[200005], t[200005];
    scanf("%s %s", s, t);
    int n = strlen(s), m = strlen(t);
    int min_len = 1e9, start = -1;
    for(int i=0; i<=n-m; i++) {
        int j=0, k=i;
        while(j<m && k<n) {
            if(s[k] == t[j]) j++;
            k++;
        }
        if(j == m) {
            int len = k - i;
            if(len < min_len) { min_len = len; start = i; }
        }
    }
    if(start == -1) printf("\n");
    else {
        char res[200005];
        strncpy(res, s+start, min_len);
        res[min_len] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
