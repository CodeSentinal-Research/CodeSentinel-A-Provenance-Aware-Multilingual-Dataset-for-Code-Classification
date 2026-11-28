#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestSemiRepetitiveSubstring(char* s) {
    int ans = 1, l = 0, lastRepeat = 0;

    for (int r = 1; s[r]; r++) {
        if (s[r] == s[r - 1]) {
            if (lastRepeat > 0) l = lastRepeat;
            lastRepeat = r;
        }
        ans = MAX(ans, r - l + 1);
    }
    return ans;
}