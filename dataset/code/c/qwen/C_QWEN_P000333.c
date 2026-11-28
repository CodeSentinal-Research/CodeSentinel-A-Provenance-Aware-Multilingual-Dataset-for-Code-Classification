#include <stdio.h>
#include <string.h>
int main() {
    char s[50001]; int n; scanf("%s %d", s, &n);
    char words[5000][51];
    for(int i=0; i<n; i++) scanf("%s", words[i]);
    int count = 0;
    for(int i=0; i<n; i++) {
        int j=0, k=0;
        while(s[j] && words[i][k]) {
            if(s[j] == words[i][k]) k++;
            j++;
        }
        if(words[i][k] == '\0') count++;
    }
    printf("%d\n", count);
    return 0;
}
