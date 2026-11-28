#include <stdio.h>
#include <string.h>
int main() {
    char a[100001], b[100001]; scanf("%s%s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    int max_l = l1 > l2 ? l1 : l2;
    char res[100002]; int idx = 0, carry = 0;
    int i = l1 - 1, j = l2 - 1;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        res[idx++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    for(int i=idx-1; i>=0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}
