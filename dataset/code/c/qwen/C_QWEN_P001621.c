#include <stdio.h>
#include <string.h>

int main() {
    char s[200005]; scanf("%s", s);
    int n = strlen(s);
    long long prefix[n+1]; prefix[0] = 0;
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + (s[i] - 'a' + 1);
    }
    for(int i=1; i<=n; i++) printf("%lld%c", prefix[i], i==n?'\n':' ');
    return 0;
}
