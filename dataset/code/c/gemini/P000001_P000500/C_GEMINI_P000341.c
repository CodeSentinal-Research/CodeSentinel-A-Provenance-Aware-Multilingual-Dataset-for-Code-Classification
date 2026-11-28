#include <stdio.h>
#include <string.h>

long long wordToVal(const char* w) {
    long long val = 0;
    for (int i = 0; w[i]; i++) {
        val = val * 10 + (w[i] - 'a');
    }
    return val;
}

int main() {
    char w1[16], w2[16], w3[16];
    if (scanf("%15s %15s %15s", w1, w2, w3) == 3) {
        printf("%s\n", wordToVal(w1) + wordToVal(w2) == wordToVal(w3) ? "Yes" : "No");
    }
    return 0;
}