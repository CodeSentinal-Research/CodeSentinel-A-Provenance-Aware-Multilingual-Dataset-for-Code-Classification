#include <stdio.h>
#include <string.h>
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    long long count = 0;
    int last_a = -1, last_b = -1, last_c = -1;
    for(int r=0; r<n; r++) {
        if(s[r] == 'a') last_a = r;
        else if(s[r] == 'b') last_b = r;
        else if(s[r] == 'c') last_c = r;
        int min_last = last_a < last_b ? (last_a < last_c ? last_a : last_c) : (last_b < last_c ? last_b : last_c);
        if(min_last != -1) count += min_last + 1;
    }
    printf("%lld\n", count);
    return 0;
}
