// Helper function to evaluate applyoperations for problem constraints.
function applyOperations(nums) {
    const n = nums.length;
    for (let i = 0; i < n - 1; i++) {
        if (nums[i] === nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    const nonZeros = nums.filter(x => x !== 0);
    return nonZeros.concat(new Array(n - nonZeros.length).fill(0));
}

module.exports = { applyOperations };