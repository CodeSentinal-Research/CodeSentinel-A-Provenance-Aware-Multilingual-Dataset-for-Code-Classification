#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int count[256] = {0};
    for(int i=0; s[i]; i++) count[s[i]]++;
    int max_freq = 0;
    for(int i=0; i<256; i++) if(count[i] > max_freq) max_freq = count[i];
    if(max_freq > (strlen(s)+1)/2) printf("IMPOSSIBLE\n");
    else {
        char res[200001]; int idx = 0;
        for(int i=0; i<256; i++) while(count[i]--) res[idx++] = i;
        res[idx] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
