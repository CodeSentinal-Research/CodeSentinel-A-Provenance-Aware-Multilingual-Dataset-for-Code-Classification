#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char emails[100000][50];
    for(int i=0; i<n; i++) scanf("%s", emails[i]);
    char domain[50]; scanf("%s", domain);
    int found = 0;
    for(int i=0; i<n; i++) {
        int len = strlen(emails[i]), dlen = strlen(domain);
        if(len > dlen && strcmp(emails[i]+len-dlen, domain)==0) { printf("%s\n", emails[i]); found=1; }
    }
    if(!found) printf("No Emails Found\n");
    return 0;
}
