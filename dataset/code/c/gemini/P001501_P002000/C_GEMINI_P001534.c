#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstringTwoDistinct(char* s) {
    int count[256] = {0};
    int distinct = 0, l = 0, maxLen = 0;

    for (int r = 0; s[r]; r++) {
        unsigned char c = (unsigned char)s[r];
        if (count[c]++ == 0) distinct++;
        while (distinct > 2) {
            unsigned char left = (unsigned char)s[l++];
            if (--count[left] == 0) distinct--;
        }
        maxLen = MAX(maxLen, r - l + 1);
    }
    return maxLen;
}