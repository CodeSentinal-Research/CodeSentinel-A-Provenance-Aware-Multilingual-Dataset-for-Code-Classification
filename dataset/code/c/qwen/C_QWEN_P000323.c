#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int a=0, l=0, max_l=0, curr_l=0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='A') a++;
        if(s[i]=='L') { curr_l++; if(curr_l>max_l) max_l=curr_l; }
        else curr_l = 0;
    }
    printf("%s\n", (a<2 && max_l<3) ? "Yes" : "No");
    return 0;
}
