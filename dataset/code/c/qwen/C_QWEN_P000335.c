#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char queries[100][101], pattern[101];
    for(int i=0; i<n; i++) scanf("%s", queries[i]);
    scanf("%s", pattern);
    for(int i=0; i<n; i++) {
        int j=0, k=0, valid=1;
        while(j < strlen(queries[i])) {
            if(k < strlen(pattern) && queries[i][j] == pattern[k]) { j++; k++; }
            else if(queries[i][j] >= 'A' && queries[i][j] <= 'Z') { valid=0; break; }
            else j++;
        }
        printf("%s\n", (valid && k == strlen(pattern)) ? "true" : "false");
    }
    return 0;
}
