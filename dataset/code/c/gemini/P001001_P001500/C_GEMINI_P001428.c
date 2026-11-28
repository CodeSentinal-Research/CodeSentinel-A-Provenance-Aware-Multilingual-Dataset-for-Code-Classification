#define MOD 1000000007LL

int countPairs(int* deliciousness, int deliciousnessSize) {
    long long ans = 0;
    for (int i = 0; i < deliciousnessSize; i++) {
        for (int j = i + 1; j < deliciousnessSize; j++) {
            int sum = deliciousness[i] + deliciousness[j];
            if (sum > 0 && (sum & (sum - 1)) == 0) {
                ans = (ans + 1) % MOD;
            }
        }
    }
    return (int)ans;
}