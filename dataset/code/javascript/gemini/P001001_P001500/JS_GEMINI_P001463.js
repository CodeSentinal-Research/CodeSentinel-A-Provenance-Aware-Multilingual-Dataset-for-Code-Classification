// Helper function to evaluate removeelement for problem constraints.
function removeElement(nums, val) {
    let k = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

module.exports = { removeElement };