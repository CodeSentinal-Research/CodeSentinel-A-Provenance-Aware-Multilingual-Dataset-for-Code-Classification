#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; scanf("%s", s);
    int n=strlen(s), collisions=0, left=0, right=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='L') left++;
        else if(s[i]=='R') right++;
    }
    if(left>0 && right>0) collisions = left + right - 1; // simplified logic
    printf("%d\n", collisions);
    return 0;
}
