#include <stdio.h>
#include <string.h>

void multiply(const char* num1, const char* num2, char* out) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        strcpy(out, "0");
        return;
    }
    int m = strlen(num1), n = strlen(num2);
    int pos[500] = {0};
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            pos[p2] = sum % 10;
            pos[p1] += sum / 10;
        }
    }
    int idx = 0;
    while (idx < m + n && pos[idx] == 0) idx++;
    int out_idx = 0;
    while (idx < m + n) {
        out[out_idx++] = pos[idx++] + '0';
    }
    out[out_idx] = '\0';
}

int main() {
    char s1[205], s2[205];
    if (scanf("%204s %204s", s1, s2) == 2) {
        char res[500] = {0};
        multiply(s1, s2, res);
        printf("%s\n", res);
    }
    return 0;
}