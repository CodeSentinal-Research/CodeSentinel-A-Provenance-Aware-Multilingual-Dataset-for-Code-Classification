#include <stdio.h>
#include <string.h>
int is_vowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }
int main() {
    char s[200005];
    scanf("%s", s);
    int n = strlen(s);
    long long count = 0;
    int last_pos[32];
    for(int i=0; i<32; i++) last_pos[i] = -1;
    last_pos[0] = 0; // simplified logic for prefix sum
    // Actually O(N) with prefix sum array of size 32
    int prefix[200005][32]; // too large for stack, use global or dynamic
    // Fallback to O(N * 32) or O(N^2) if N is small, but N=2e5.
    // Let's use a simple O(N) approach with hash map of 32 states
    int count_map[32];
    for(int i=0; i<32; i++) count_map[i] = 0;
    int cur_mask = 0;
    count_map[0] = 1; // wait, we need exact 5 vowels.
    // Actually, just count substrings with all 5 vowels.
    // Sliding window: at least 5 vowels - at least 6 vowels (impossible) -> at least 5.
    // Let's use sliding window for at least 5 vowels.
    long long at_least_5 = 0;
    int l = 0, distinct = 0, v_count[256] = {0};
    for(int r=0; r<n; r++) {
        if(is_vowel(s[r])) {
            if(v_count[s[r]] == 0) distinct++;
            v_count[s[r]]++;
        }
        while(distinct == 5) {
            at_least_5 += n - r;
            if(is_vowel(s[l])) {
                v_count[s[l]]--;
                if(v_count[s[l]] == 0) distinct--;
            }
            l++;
        }
    }
    printf("%lld\n", at_least_5);
    return 0;
}
