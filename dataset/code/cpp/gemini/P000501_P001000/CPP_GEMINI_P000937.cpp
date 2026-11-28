#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

std::vector<std::vector<long long>> matMul(const std::vector<std::vector<long long>>& a,
                                          const std::vector<std::vector<long long>>& b) {
    int n = a.size();
    std::vector<std::vector<long long>> res(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

std::vector<std::vector<long long>> matPow(std::vector<std::vector<long long>> mat, long long p) {
    int n = mat.size();
    std::vector<std::vector<long long>> res(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        // If current bit is set, multiply base into result
        if (p % 2 == 1) res = matMul(res, mat);
        mat = matMul(mat, mat);
        p /= 2;
    }
    return res;
}

int main() {
    int n;
    long long p;
    if (std::cin >> n >> p && n > 0) {
        std::vector<std::vector<long long>> mat(n, std::vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cin >> mat[i][j];
        }
        auto ans = matPow(mat, p);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << ans[i][j] << (j == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}