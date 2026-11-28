#include <stdio.h>
#include <ctype.h>
int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        int n = 0, d_sum = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (isdigit(s[i])) { d_sum += s[i] - '0'; n = n * 10 + (s[i] - '0'); }
        }
        printf("%s\n", d_sum > 0 && n % d_sum == 0 ? "Harshad" : "Not Harshad");
    }
    return 0;
}