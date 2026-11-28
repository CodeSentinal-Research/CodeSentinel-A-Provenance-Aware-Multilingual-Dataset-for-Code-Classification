#include <stdio.h>
#include <string.h>
int main() {
    char s[501], t[501]; scanf("%s %s", s, t);
    int count[256]={0}, required=strlen(t), formed=0, min_len=1000000, start=0;
    for(int i=0; t[i]; i++) count[t[i]]++;
    int window[256]={0}, l=0;
    for(int r=0; s[r]; r++) {
        window[s[r]]++;
        if(count[s[r]] > 0 && window[s[r]] <= count[s[r]]) formed++;
        while(formed == required) {
            if(r-l+1 < min_len) { min_len=r-l+1; start=l; }
            window[s[l]]--;
            if(count[s[l]] > 0 && window[s[l]] < count[s[l]]) formed--;
            l++;
        }
    }
    if(min_len == 1000000) printf("\n");
    else { char res[501]; strncpy(res, s+start, min_len); res[min_len]='\0'; printf("%s\n", res); }
    return 0;
}
