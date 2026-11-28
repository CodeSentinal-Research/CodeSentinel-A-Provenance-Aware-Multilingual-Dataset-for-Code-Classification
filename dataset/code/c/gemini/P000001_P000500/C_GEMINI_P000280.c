#include <string.h>
#include <stdbool.h>

bool validAnagramAfterRemoval(char* s, char* t) {
    if (strlen(s) != strlen(t) + 1) return false;
    int freqS[256] = {0}, freqT[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) freqS[(unsigned char)s[i]]++;
    for (int i = 0; t[i] != '\0'; i++) freqT[(unsigned char)t[i]]++;

    int diff = 0;
    for (int i = 0; i < 256; i++) {
        if (freqS[i] > freqT[i]) diff += freqS[i] - freqT[i];
        else if (freqS[i] < freqT[i]) return false;
    }
    return diff == 1;
}