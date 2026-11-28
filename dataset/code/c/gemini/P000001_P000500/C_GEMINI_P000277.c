#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    if (scanf("%999s", s) == 1) {
        int map[256] = {0}, left = 0, max_len = 0, len = strlen(s);
        // Expand window to the right
        for (int right = 0; right < len; right++) {
            // Shrink window from the left while duplicate exists
            while (map[(unsigned char)s[right]]) map[(unsigned char)s[left++]] = 0;
            map[(unsigned char)s[right]] = 1;
            if (right - left + 1 > max_len) max_len = right - left + 1;
        }
        printf("%d\n", max_len);
    }
    return 0;
}