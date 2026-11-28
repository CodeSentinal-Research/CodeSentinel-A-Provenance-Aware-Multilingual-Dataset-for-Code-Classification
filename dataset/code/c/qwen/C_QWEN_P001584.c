#include <stdio.h>
#include <string.h>
int is_vowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
int main() {
    char s[200005]; int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    int max_len = 0, l = 0, vowel_count = 0;
    for(int r=0; r<n; r++) {
        if(is_vowel(s[r])) vowel_count++;
        while(vowel_count > k) { if(is_vowel(s[l])) vowel_count--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
