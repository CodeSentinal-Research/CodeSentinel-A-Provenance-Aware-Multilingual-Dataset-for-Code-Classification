// Helper function to evaluate singlenumber for problem constraints.
function singleNumber(nums) {
    let xorAll = 0;
    for (const x of nums) xorAll ^= x;
    const diff = xorAll & (-xorAll);
    let a = 0, b = 0;
    for (const x of nums) {
        if ((x & diff) !== 0) a ^= x;
        else b ^= x;
    }
    return [a, b];
}

module.exports = { singleNumber };