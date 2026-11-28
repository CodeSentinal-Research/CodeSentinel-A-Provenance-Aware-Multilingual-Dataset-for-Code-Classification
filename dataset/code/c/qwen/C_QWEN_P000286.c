#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int l=0, r=strlen(s)-1;
    while(l<r) {
        while(l<r && !((s[l]>='a'&&s[l]<='z')||(s[l]>='A'&&s[l]<='Z'))) l++;
        while(l<r && !((s[r]>='a'&&s[r]<='z')||(s[r]>='A'&&s[r]<='Z'))) r--;
        if(l<r) { char t=s[l]; s[l]=s[r]; s[r]=t; l++; r--; }
    }
    printf("%s\n", s);
    return 0;
}
