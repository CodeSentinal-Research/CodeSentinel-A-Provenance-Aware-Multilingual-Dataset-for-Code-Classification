#include <stdio.h>
#include <string.h>
int is_vowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'; }
int main() {
    char s[200005]; int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    int cur = 0, max_vowels = 0;
    for(int i=0; i<n; i++) {
        if(i < k && is_vowel(s[i])) cur++;
    }
    max_vowels = cur;
    for(int i=k; i<n; i++) {
        if(is_vowel(s[i])) cur++;
        if(is_vowel(s[i-k])) cur--;
        if(cur > max_vowels) max_vowels = cur;
    }
    printf("%d\n", max_vowels);
    return 0;
}
