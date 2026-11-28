char nonrepeatingCharacter(char* s) {
    int freq[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) freq[(unsigned char)s[i]]++;
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[(unsigned char)s[i]] == 1) return s[i];
    }
    return '$';
}