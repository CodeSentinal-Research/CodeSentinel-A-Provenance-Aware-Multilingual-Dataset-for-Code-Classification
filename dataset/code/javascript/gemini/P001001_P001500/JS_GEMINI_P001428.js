// Helper function to evaluate countpairs for problem constraints.
function countPairs(deliciousness) {
    const MOD = 1000000007n;
    const map = new Map();
    let ans = 0n;

    for (const x of deliciousness) {
        for (let i = 0; i <= 21; i++) {
            const target = (1 << i) - x;
            if (map.has(target)) {
                ans = (ans + BigInt(map.get(target))) % MOD;
            }
        }
        map.set(x, (map.get(x) || 0) + 1);
    }
    return Number(ans);
}

module.exports = { countPairs };