// Helper function to evaluate permute for problem constraints.
function permute(nums) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(first) {
        if (first === nums.length) {
            res.push([...nums]);
            return;
        }
        for (let i = first; i < nums.length; i++) {
            [nums[first], nums[i]] = [nums[i], nums[first]];
            backtrack(first + 1);
            [nums[first], nums[i]] = [nums[i], nums[first]];
        }
    }

    backtrack(0);
    return res;
}

module.exports = { permute };