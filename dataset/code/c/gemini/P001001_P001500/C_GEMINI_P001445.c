int numMatchingSubseq(char* s, char** words, int wordsSize) {
    int ans = 0;
    for (int k = 0; k < wordsSize; k++) {
        char* w = words[k];
        int i = 0, j = 0;
        while (s[i] && w[j]) {
            if (s[i] == w[j]) j++;
            i++;
        }
        if (w[j] == '\0') ans++;
    }
    return ans;
}