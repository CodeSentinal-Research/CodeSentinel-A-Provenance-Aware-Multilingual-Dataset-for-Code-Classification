#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxNumberOfBalloons(char* text) {
    int count[26] = {0};
    for (int i = 0; text[i]; i++) count[text[i] - 'a']++;

    int b = count['b' - 'a'];
    int a = count['a' - 'a'];
    int l = count['l' - 'a'] / 2;
    int o = count['o' - 'a'] / 2;
    int n = count['n' - 'a'];

    return MIN(b, MIN(a, MIN(l, MIN(o, n))));
}