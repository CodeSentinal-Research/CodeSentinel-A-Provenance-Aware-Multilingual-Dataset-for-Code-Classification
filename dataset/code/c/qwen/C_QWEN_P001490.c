#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    int count = 0;
    int i = 0;
    while (i < n) {
        char c = s[i];
        int len = 0;
        while (i < n && s[i] == c) { len++; i++; }
        if (c == '0') {
            int j = i;
            int len1 = 0;
            while (j < n && s[j] == '1') { len1++; j++; }
            if (len1 >= len) count += len;
        } else {
            int j = i;
            int len1 = 0;
            while (j < n && s[j] == '0') { len1++; j++; }
            if (len1 >= len) count += len;
        }
    }
    printf("%d\n", count);
    return 0;
}
