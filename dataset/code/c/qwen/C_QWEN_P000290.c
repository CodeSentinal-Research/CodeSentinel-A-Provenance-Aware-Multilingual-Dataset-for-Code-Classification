#include <stdio.h>
#include <string.h>
int main() {
    char text[1001], pattern[1001]; scanf("%s %s", text, pattern);
    int count_p[256]={0}, count_w[256]={0}, p_len=strlen(pattern), formed=0, required=0;
    for(int i=0; pattern[i]; i++) { count_p[pattern[i]]++; if(count_p[pattern[i]]==1) required++; }
    int first=1;
    for(int i=0; text[i]; i++) {
        count_w[text[i]]++;
        if(count_p[text[i]] > 0 && count_w[text[i]] == count_p[text[i]]) formed++;
        if(i >= p_len) {
            count_w[text[i-p_len]]--;
            if(count_p[text[i-p_len]] > 0 && count_w[text[i-p_len]] < count_p[text[i-p_len]]) formed--;
        }
        if(formed == required) { if(!first) printf(" "); printf("%d", i-p_len+1); first=0; }
    }
    printf("\n");
    return 0;
}
