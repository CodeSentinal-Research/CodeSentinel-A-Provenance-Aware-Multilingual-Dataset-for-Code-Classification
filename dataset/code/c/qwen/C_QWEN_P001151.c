#include <stdio.h>
#include <string.h>
int main() {
    char s[5001]; scanf("%s", s);
    int n = strlen(s), start = 0, max_l = 1;
    for(int i=0; i<n; i++) {
        int l=i, r=i;
        while(l>=0 && r<n && s[l]==s[r]) { if(r-l+1 > max_l) { max_l = r-l+1; start = l; } l--; r++; }
        l=i; r=i+1;
        while(l>=0 && r<n && s[l]==s[r]) { if(r-l+1 > max_l) { max_l = r-l+1; start = l; } l--; r++; }
    }
    char res[5001]; strncpy(res, s+start, max_l); res[max_l] = '\0';
    printf("%s\n", res);
    return 0;
}
