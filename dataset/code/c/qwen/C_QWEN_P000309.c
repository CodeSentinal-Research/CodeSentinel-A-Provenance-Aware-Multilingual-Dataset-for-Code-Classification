#include <stdio.h>
#include <string.h>
int main() {
    char n1[201], n2[201]; scanf("%s %s", n1, n2);
    int l1 = strlen(n1), l2 = strlen(n2);
    int res[401] = {0};
    for(int i=l1-1; i>=0; i--) {
        for(int j=l2-1; j>=0; j--) {
            res[i+j+1] += (n1[i]-'0') * (n2[j]-'0');
            res[i+j] += res[i+j+1] / 10;
            res[i+j+1] %= 10;
        }
    }
    int start = 0;
    while(start < 400 && res[start] == 0) start++;
    if(start == 401) printf("0\n");
    else { for(int i=start; i<401; i++) printf("%d", res[i]); printf("\n"); }
    return 0;
}
