// Helper function to evaluate countparenthesization for problem constraints.
function countParenthesization(s) {
    const MOD = 1003n;
    const n = s.length;
    const m = Math.floor((n + 1) / 2);
    const symbols = [];
    const operators = [];
    for (let i = 0; i < n; i++) {
        if (i % 2 === 0) symbols.push(s[i]);
        else operators.push(s[i]);
    }

    const T = Array.from({ length: m }, () => new Array(m).fill(0n));
    const F = Array.from({ length: m }, () => new Array(m).fill(0n));

    for (let i = 0; i < m; i++) {
        T[i][i] = symbols[i] === 'T' ? 1n : 0n;
        F[i][i] = symbols[i] === 'F' ? 1n : 0n;
    }

    for (let len = 2; len <= m; len++) {
        for (let i = 0; i <= m - len; i++) {
            const j = i + len - 1;
            for (let k = i; k < j; k++) {
                const op = operators[k];
                const totalIK = (T[i][k] + F[i][k]) % MOD;
                const totalKJ = (T[k + 1][j] + F[k + 1][j]) % MOD;

                if (op === '&') {
                    T[i][j] = (T[i][j] + T[i][k] * T[k + 1][j]) % MOD;
                    F[i][j] = (F[i][j] + totalIK * totalKJ - T[i][k] * T[k + 1][j]) % MOD;
                } else if (op === '|') {
                    F[i][j] = (F[i][j] + F[i][k] * F[k + 1][j]) % MOD;
                    T[i][j] = (T[i][j] + totalIK * totalKJ - F[i][k] * F[k + 1][j]) % MOD;
                } else if (op === '^') {
                    T[i][j] = (T[i][j] + T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j]) % MOD;
                    F[i][j] = (F[i][j] + T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j]) % MOD;
                }
            }
        }
    }
    return Number((T[0][m - 1] % MOD + MOD) % MOD);
}

module.exports = { countParenthesization };