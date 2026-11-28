#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    
    int count[256] = {0};
    for (int i = 0; s[i]; i++) count[s[i]]++;
    
    int b = count['b'], a = count['a'], l = count['l'], o = count['o'], n = count['n'];
    int ans = l / 2;
    if (ans > o / 2) ans = o / 2;
    if (ans > b) ans = b;
    if (ans > a) ans = a;
    if (ans > n) ans = n;
    
    printf("%d\n", ans);
    return 0;
}
