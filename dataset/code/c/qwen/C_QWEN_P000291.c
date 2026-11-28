#include <stdio.h>
#include <string.h>
int main() {
    char s1[1001], s2[1001]; scanf("%s %s", s1, s2);
    if(strlen(s1) > strlen(s2)) { printf("No\n"); return 0; }
    int count1[256]={0}, count2[256]={0}, p_len=strlen(s1), formed=0, required=0;
    for(int i=0; s1[i]; i++) { count1[s1[i]]++; if(count1[s1[i]]==1) required++; }
    for(int i=0; s2[i]; i++) {
        count2[s2[i]]++;
        if(count1[s2[i]] > 0 && count2[s2[i]] == count1[s2[i]]) formed++;
        if(i >= p_len) {
            count2[s2[i-p_len]]--;
            if(count1[s2[i-p_len]] > 0 && count2[s2[i-p_len]] < count1[s2[i-p_len]]) formed--;
        }
        if(formed == required) { printf("Yes\n"); return 0; }
    }
    printf("No\n");
    return 0;
}
