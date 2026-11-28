#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char num[101]; int a, b; scanf("%s%d%d", num, &a, &b);
    long long dec = 0;
    for(int i=0; num[i]; i++) {
        int val = isdigit(num[i]) ? num[i] - '0' : num[i] - 'A' + 10;
        dec = dec * a + val;
    }
    if(dec == 0) { printf("0\n"); return 0; }
    char res[101]; int idx = 0;
    while(dec > 0) {
        int rem = dec % b;
        res[idx++] = rem < 10 ? rem + '0' : rem - 10 + 'A';
        dec /= b;
    }
    for(int i=idx-1; i>=0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}
