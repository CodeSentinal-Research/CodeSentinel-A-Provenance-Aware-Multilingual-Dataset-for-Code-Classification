#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Calculates modular exponentiation (base^exp % mod) efficiently.
int maxPower(char* s) {
    int maxRun = 1, curRun = 1;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1]) {
            curRun++;
            maxRun = MAX(maxRun, curRun);
        } else {
            curRun = 1;
        }
    }
    return maxRun;
}