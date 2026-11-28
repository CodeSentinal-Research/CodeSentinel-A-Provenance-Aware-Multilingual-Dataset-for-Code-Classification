function containsContiguous(nums) {
    if (!nums.length) return true;
    const s = new Set(nums);
    if (s.size !== nums.length) return false;
    return Math.max(...nums) - Math.min(...nums) === nums.length - 1;
}
module.exports = { containsContiguous };
