#include <stdio.h>
#include <string.h>

void addBinary(const char* a, const char* b, char* out) {
    int i = strlen(a) - 1, j = strlen(b) - 1, carry = 0, k = 0;
    char temp[2005];
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        temp[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    for (int l = 0; l < k; l++) {
        out[l] = temp[k - 1 - l];
    }
    out[k] = '\0';
}

int main() {
    char a[1005], b[1005], res[2005];
    if (scanf("%1004s %1004s", a, b) == 2) {
        addBinary(a, b, res);
        printf("%s\n", res);
    }
    return 0;
}