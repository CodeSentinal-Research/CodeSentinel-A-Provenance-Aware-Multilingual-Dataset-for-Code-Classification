#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char products[100000][50];
    for(int i=0; i<n; i++) scanf("%s", products[i]);
    char suffix[50]; scanf("%s", suffix);
    int found = 0;
    for(int i=0; i<n; i++) {
        int len = strlen(products[i]), slen = strlen(suffix);
        if(len >= slen && strcmp(products[i]+len-slen, suffix)==0) { printf("%s\n", products[i]); found=1; }
    }
    if(!found) printf("No Products Found\n");
    return 0;
}
