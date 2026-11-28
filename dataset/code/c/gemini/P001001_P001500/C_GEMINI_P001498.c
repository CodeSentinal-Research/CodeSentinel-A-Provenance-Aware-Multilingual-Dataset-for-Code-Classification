long long minimumSteps(char* s) {
    long long ans = 0;
    long long ones = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') ones++;
        else ans += ones;
    }
    return ans;
}