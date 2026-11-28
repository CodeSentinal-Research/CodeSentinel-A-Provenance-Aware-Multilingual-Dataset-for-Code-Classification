#include <stdio.h>
#include <string.h>
int is_vowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    long long count = 0;
    for(int i=0; i<n; i++) {
        if(!is_vowel(s[i])) continue;
        int mask = 0;
        for(int j=i; j<n; j++) {
            if(!is_vowel(s[j])) break;
            if(s[j]=='a') mask|=1; else if(s[j]=='e') mask|=2; else if(s[j]=='i') mask|=4; else if(s[j]=='o') mask|=8; else if(s[j]=='u') mask|=16;
            if(mask == 31) count++;
        }
    }
    printf("%lld\n", count);
    return 0;
}
