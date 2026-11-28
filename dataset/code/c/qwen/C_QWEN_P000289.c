#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; int k; scanf("%s %d", s, &k);
    int count[256]={0}, max_freq=0, max_len=0, left=0;
    for(int right=0; s[right]; right++) {
        count[s[right]]++;
        if(count[s[right]] > max_freq) max_freq = count[s[right]];
        while(right - left + 1 - max_freq > k) { count[s[left]]--; left++; }
        if(right - left + 1 > max_len) max_len = right - left + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
