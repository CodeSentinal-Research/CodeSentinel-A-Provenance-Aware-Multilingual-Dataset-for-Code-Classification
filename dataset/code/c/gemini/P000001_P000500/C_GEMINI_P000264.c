void getFrequencies(char* s, int freq[256]) {
    for (int i = 0; i < 256; i++) freq[i] = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }
}