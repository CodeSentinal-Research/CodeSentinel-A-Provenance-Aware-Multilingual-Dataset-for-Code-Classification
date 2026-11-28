// Helper function to evaluate canarrange for problem constraints.
function canArrange(arr, k) {
    const rem = new Array(k).fill(0);
    for (const x of arr) {
        const r = ((x % k) + k) % k;
        rem[r]++;
    }

    if (rem[0] % 2 !== 0) return false;
    for (let i = 1; i <= Math.floor(k / 2); i++) {
        if (i * 2 === k) {
            if (rem[i] % 2 !== 0) return false;
        } else if (rem[i] !== rem[k - i]) {
            return false;
        }
    }
    return true;
}

module.exports = { canArrange };