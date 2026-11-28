function rotateRight(nums, k) {
    const n = nums.length;
    if (!n) return nums;
    k = ((k % n) + n) % n;
    return [...nums.slice(n - k), ...nums.slice(0, n - k)];
}
module.exports = { rotateRight };
