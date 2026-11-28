#include <stdio.h>
#include <string.h>

int compareVersion(const char* v1, const char* v2) {
    int i = 0, j = 0, n1 = strlen(v1), n2 = strlen(v2);
    while (i < n1 || j < n2) {
        int num1 = 0, num2 = 0;
        while (i < n1 && v1[i] != '.') {
            num1 = num1 * 10 + (v1[i++] - '0');
        }
        while (j < n2 && v2[j] != '.') {
            num2 = num2 * 10 + (v2[j++] - '0');
        }
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        i++;
        j++;
    }
    return 0;
}

int main() {
    char v1[505], v2[505];
    if (scanf("%504s %504s", v1, v2) == 2) {
        printf("%d\n", compareVersion(v1, v2));
    }
    return 0;
}