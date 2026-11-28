#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int count[256]={0}, max_len=0, left=0;
    for(int right=0; s[right]; right++) {
        count[s[right]]++;
        while(count[s[right]] > 1) { count[s[left]]--; left++; }
        if(right - left + 1 > max_len) max_len = right - left + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
