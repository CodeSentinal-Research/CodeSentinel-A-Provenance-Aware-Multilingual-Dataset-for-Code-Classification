#include <stdio.h>
#include <string.h>
int main() {
    char s[501]; scanf("%s", s);
    int n = strlen(s), zeros=0, ones=0, max_score=0;
    for(int i=0; i<n; i++) if(s[i]=='1') ones++;
    int left_zeros=0, left_ones=0;
    for(int i=0; i<n-1; i++) {
        if(s[i]=='0') left_zeros++; else left_ones++;
        int score = left_zeros + (ones - left_ones);
        if(score > max_score) max_score = score;
    }
    printf("%d\n", max_score);
    return 0;
}
