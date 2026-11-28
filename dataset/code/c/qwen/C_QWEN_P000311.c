#include <stdio.h>
#include <string.h>
int main() {
    char n1[1001], n2[1001]; scanf("%s %s", n1, n2);
    int l1 = strlen(n1), l2 = strlen(n2);
    char res[1002]; int i=l1-1, j=l2-1, k=0, carry=0;
    while(i>=0 || j>=0 || carry) {
        int sum = carry;
        if(i>=0) sum += n1[i--]-'0';
        if(j>=0) sum += n2[j--]-'0';
        res[k++] = (sum%10) + '0';
        carry = sum/10;
    }
    for(int i=k-1; i>=0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}
