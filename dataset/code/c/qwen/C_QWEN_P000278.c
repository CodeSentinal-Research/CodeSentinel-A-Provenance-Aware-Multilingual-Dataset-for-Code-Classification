#include <stdio.h>
#include <string.h>
int main() {
    char s[501]; scanf("%s", s);
    int len=strlen(s), start=0, max_len=1;
    for(int i=0; i<len; i++) {
        int l=i, r=i;
        while(l>=0 && r<len && s[l]==s[r]) { if(r-l+1 > max_len) { max_len=r-l+1; start=l; } l--; r++; }
        l=i; r=i+1;
        while(l>=0 && r<len && s[l]==s[r]) { if(r-l+1 > max_len) { max_len=r-l+1; start=l; } l--; r++; }
    }
    char res[501]; strncpy(res, s+start, max_len); res[max_len]='\0';
    printf("%s\n", res);
    return 0;
}
