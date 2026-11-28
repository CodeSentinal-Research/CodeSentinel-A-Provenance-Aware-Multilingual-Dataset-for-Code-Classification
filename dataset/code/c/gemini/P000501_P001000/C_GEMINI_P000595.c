#include <stdio.h>
#include <string.h>
#define MAX_N 100005
int l1[MAX_N], l2[MAX_N], res[MAX_N];
int main() {
    char line1[MAX_N], line2[MAX_N];
    if (fgets(line1, sizeof(line1), stdin)) {
        int n1 = 0, n2 = 0;
        char* tok = strtok(line1, " \t\r\n");
        while (tok) { l1[n1++] = atoi(tok); tok = strtok(NULL, " \t\r\n"); }
        if (fgets(line2, sizeof(line2), stdin)) {
            tok = strtok(line2, " \t\r\n");
            while (tok) { l2[n2++] = atoi(tok); tok = strtok(NULL, " \t\r\n"); }
        }
        int s1 = 0, s2 = 0;
        if (n1 > 0 && n1 - 1 == l1[0]) s1 = 1;
        if (n2 > 0 && n2 - 1 == l2[0]) s2 = 1;
        int i = s1, j = s2, carry = 0, r_cnt = 0;
        while (i < n1 || j < n2 || carry) {
            int v1 = (i < n1) ? l1[i] : 0;
            int v2 = (j < n2) ? l2[j] : 0;
            int sum = v1 + v2 + carry;
            res[r_cnt++] = sum % 10;
            carry = sum / 10;
            i++; j++;
        }
        for (int k = 0; k < r_cnt; k++) printf("%d%s", res[k], k == r_cnt - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}