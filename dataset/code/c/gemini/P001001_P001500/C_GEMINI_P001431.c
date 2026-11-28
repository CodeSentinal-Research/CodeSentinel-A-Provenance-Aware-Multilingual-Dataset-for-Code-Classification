int similarPairs(char** words, int wordsSize) {
    int ans = 0;
    int masks[105];

    for (int i = 0; i < wordsSize; i++) {
        int mask = 0;
        for (int j = 0; words[i][j]; j++) {
            mask |= (1 << (words[i][j] - 'a'));
        }
        masks[i] = mask;
    }

    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (masks[i] == masks[j]) ans++;
        }
    }
    return ans;
}