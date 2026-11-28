function rotateLeft(nums, k) {
    const n = nums.length;
    if (!n) return nums;
    k = ((k % n) + n) % n;
    return [...nums.slice(k), ...nums.slice(0, k)];
}
module.exports = { rotateLeft };
