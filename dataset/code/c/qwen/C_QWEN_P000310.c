#include <stdio.h>
#include <string.h>
int main() {
    char a[1001], b[1001]; scanf("%s %s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    char res[1002]; int i=l1-1, j=l2-1, k=0, carry=0;
    while(i>=0 || j>=0 || carry) {
        int sum = carry;
        if(i>=0) sum += a[i--]-'0';
        if(j>=0) sum += b[j--]-'0';
        res[k++] = (sum%2) + '0';
        carry = sum/2;
    }
    for(int i=k-1; i>=0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}
