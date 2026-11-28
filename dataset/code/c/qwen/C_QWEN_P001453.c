#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    
    int max_len = 0;
    char ans_char = s[0];
    int cur_len = 1;
    
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i-1]) cur_len++;
        else {
            if (cur_len > max_len || (cur_len == max_len && s[i-1] < ans_char)) {
                max_len = cur_len;
                ans_char = s[i-1];
            }
            cur_len = 1;
        }
    }
    if (cur_len > max_len || (cur_len == max_len && s[strlen(s)-1] < ans_char)) {
        max_len = cur_len;
        ans_char = s[strlen(s)-1];
    }
    printf("%c %d\n", ans_char, max_len);
    return 0;
}
