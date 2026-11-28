// Helper function to evaluate minpatches for problem constraints.
function minPatches(nums, n) {
    let miss = 1n;
    let patches = 0, i = 0;

    while (miss <= BigInt(n)) {
        if (i < nums.length && BigInt(nums[i]) <= miss) {
            miss += BigInt(nums[i++]);
        } else {
            miss += miss;
            patches++;
        }
    }
    return patches;
}

module.exports = { minPatches };