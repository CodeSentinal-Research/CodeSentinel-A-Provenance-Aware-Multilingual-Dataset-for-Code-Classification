#include <stdio.h>
#include <string.h>

int main() {
    char v1[501], v2[501];
    scanf("%s %s", v1, v2);
    
    int i = 0, j = 0;
    while (i < strlen(v1) || j < strlen(v2)) {
        int n1 = 0, n2 = 0;
        while (i < strlen(v1) && v1[i] != '.') { n1 = n1 * 10 + (v1[i] - '0'); i++; }
        while (j < strlen(v2) && v2[j] != '.') { n2 = n2 * 10 + (v2[j] - '0'); j++; }
        if (n1 < n2) { printf("-1\n"); return 0; }
        if (n1 > n2) { printf("1\n"); return 0; }
        i++; j++;
    }
    printf("0\n");
    return 0;
}
