// Helper function to evaluate missingnumber for problem constraints.
function missingNumber(nums) {
    let ans = nums.length;
    for (let i = 0; i < nums.length; i++) {
        ans ^= (i ^ nums[i]);
    }
    return ans;
}

module.exports = { missingNumber };