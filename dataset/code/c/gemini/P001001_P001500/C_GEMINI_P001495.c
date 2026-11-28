int appendCharacters(char* s, char* t) {
    int j = 0;
    for (int i = 0; s[i] && t[j]; i++) {
        if (s[i] == t[j]) j++;
    }
    int lenT = 0;
    while (t[lenT]) lenT++;
    return lenT - j;
}