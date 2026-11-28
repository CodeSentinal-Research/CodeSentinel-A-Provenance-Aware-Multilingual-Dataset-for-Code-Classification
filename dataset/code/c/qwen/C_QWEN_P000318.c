#include <stdio.h>
#include <string.h>
int main() {
    char word[101], abbr[101]; scanf("%s %s", word, abbr);
    int i=0, j=0;
    while(i<strlen(word) && j<strlen(abbr)) {
        if(abbr[j]>='0' && abbr[j]<='9') {
            if(abbr[j]=='0') { printf("No\n"); return 0; }
            int num = 0;
            while(j<strlen(abbr) && abbr[j]>='0' && abbr[j]<='9') num = num*10 + (abbr[j++]-'0');
            i += num;
        } else {
            if(word[i] != abbr[j]) { printf("No\n"); return 0; }
            i++; j++;
        }
    }
    printf("%s\n", (i==strlen(word) && j==strlen(abbr)) ? "Yes" : "No");
    return 0;
}
