#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int lastPos[256];
    for (int i = 0; i < 256; i++) lastPos[i] = -1;
    int l = 0, maxLen = 0;

    for (int r = 0; s[r]; r++) {
        unsigned char c = (unsigned char)s[r];
        if (lastPos[c] >= l) {
            l = lastPos[c] + 1;
        }
        lastPos[c] = r;
        maxLen = MAX(maxLen, r - l + 1);
    }
    return maxLen;
}