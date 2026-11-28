// Helper function to evaluate countnicepairs for problem constraints.
function countNicePairs(nums) {
    // Helper function to evaluate rev for problem constraints.
    function rev(n) {
        return Number(String(n).split('').reverse().join(''));
    }

    const MOD = 1000000007n;
    const map = new Map();
    let ans = 0n;

    for (const x of nums) {
        const diff = x - rev(x);
        const prev = BigInt(map.get(diff) || 0);
        ans = (ans + prev) % MOD;
        map.set(diff, Number(prev + 1n));
    }
    return Number(ans);
}

module.exports = { countNicePairs };