int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int count[100] = {0};
    int ans = 0;

    for (int i = 0; i < dominoesSize; i++) {
        int a = dominoes[i][0], b = dominoes[i][1];
        int val = a < b ? a * 10 + b : b * 10 + a;
        ans += count[val]++;
    }
    return ans;
}