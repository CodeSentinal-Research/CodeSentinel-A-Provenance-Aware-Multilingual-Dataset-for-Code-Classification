#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) == 1) {
        int unbalanced = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '[') {
                if (unbalanced > 0) unbalanced--;
            } else {
                unbalanced++;
            }
        }
        printf("%d\n", (unbalanced + 1) / 2);
    }
    return 0;
}