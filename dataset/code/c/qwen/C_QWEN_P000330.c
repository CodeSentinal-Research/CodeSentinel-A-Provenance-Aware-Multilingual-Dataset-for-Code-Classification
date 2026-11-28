#include <stdio.h>
#include <string.h>
int main() {
    char s[501]; int n; scanf("%s %d", s, &n);
    char dict[100][51];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    int len = strlen(s), bold[501] = {0};
    for(int i=0; i<len; i++) {
        for(int j=0; j<n; j++) {
            int l = strlen(dict[j]);
            if(strncmp(s+i, dict[j], l) == 0) {
                for(int k=i; k<i+l; k++) bold[k] = 1;
            }
        }
    }
    int in_bold = 0;
    for(int i=0; i<len; i++) {
        if(bold[i] && !in_bold) { printf("<b>"); in_bold=1; }
        else if(!bold[i] && in_bold) { printf("</b>"); in_bold=0; }
        printf("%c", s[i]);
    }
    if(in_bold) printf("</b>");
    printf("\n");
    return 0;
}
