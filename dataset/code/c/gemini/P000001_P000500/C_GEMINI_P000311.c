#include <stdio.h>
#include <string.h>

void addStrings(const char* num1, const char* num2, char* out) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, carry = 0, k = 0;
    char temp[2005];
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    for (int l = 0; l < k; l++) {
        out[l] = temp[k - 1 - l];
    }
    out[k] = '\0';
}

int main() {
    char num1[1005], num2[1005], res[2005];
    if (scanf("%1004s %1004s", num1, num2) == 2) {
        addStrings(num1, num2, res);
        printf("%s\n", res);
    }
    return 0;
}