#include <stdio.h>
#include <string.h>
int main() {
    char s[101]; scanf("%s", s);
    int all_upper = 1, all_lower = 1, first_upper = 1;
    for(int i=0; s[i]; i++) {
        if(s[i]>='a' && s[i]<='z') all_upper = 0;
        if(s[i]>='A' && s[i]<='Z') all_lower = 0;
        if(i>0 && s[i]>='A' && s[i]<='Z') first_upper = 0;
    }
    printf("%s\n", (all_upper || all_lower || first_upper) ? "Yes" : "No");
    return 0;
}
