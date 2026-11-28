// Helper function to evaluate checkarithmeticsubarrays for problem constraints.
function checkArithmeticSubarrays(nums, l, r) {
    const res = [];
    for (let i = 0; i < l.length; i++) {
        const sub = nums.slice(l[i], r[i] + 1).sort((a, b) => a - b);
        const diff = sub[1] - sub[0];
        let isArith = true;
        for (let j = 2; j < sub.length; j++) {
            if (sub[j] - sub[j - 1] !== diff) {
                isArith = false;
                break;
            }
        }
        res.push(isArith);
    }
    return res;
}

module.exports = { checkArithmeticSubarrays };