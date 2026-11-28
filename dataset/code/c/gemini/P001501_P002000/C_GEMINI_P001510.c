#define MAX(a, b) ((a) > (b) ? (a) : (b))

int characterReplacement(char* s, int k) {
    int count[26] = {0};
    int maxFreq = 0, l = 0, len = 0;

    for (int r = 0; s[r]; r++) {
        maxFreq = MAX(maxFreq, ++count[s[r] - 'A']);
        if ((r - l + 1) - maxFreq > k) {
            count[s[l++] - 'A']--;
        }
        len++;
    }
    return len - l;
}