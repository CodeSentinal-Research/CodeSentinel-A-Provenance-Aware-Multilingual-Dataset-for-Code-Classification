#include <stdio.h>
#include <string.h>
int is_vowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
int main() {
    char s[200001]; scanf("%s", s);
    int n = strlen(s), prefix[n+1]; prefix[0]=0;
    for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + (is_vowel(s[i])?1:-1);
    int map[400001]; memset(map, 0, sizeof(map));
    map[200000] = 1; int count = 0;
    for(int i=1; i<=n; i++) { count += map[prefix[i]+200000]; map[prefix[i]+200000]++; }
    printf("%d\n", count);
    return 0;
}
