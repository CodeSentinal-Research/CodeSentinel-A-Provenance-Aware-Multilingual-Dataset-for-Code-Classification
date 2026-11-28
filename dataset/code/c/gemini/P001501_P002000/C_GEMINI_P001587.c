#define MIN(a, b) ((a) < (b) ? (a) : (b))

int numberOfSubstrings(char* s) {
    int last[3] = {-1, -1, -1};
    int ans = 0;

    for (int i = 0; s[i]; i++) {
        last[s[i] - 'a'] = i;
        ans += 1 + MIN(last[0], MIN(last[1], last[2]));
    }
    return ans;
}