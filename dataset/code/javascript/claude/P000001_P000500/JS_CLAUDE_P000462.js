function missingNumber(nums, n) {
    const expected = (n * (n + 1)) / 2;
    const actual = nums.reduce((a, b) => a + b, 0);
    return expected - actual;
}

module.exports = { missingNumber };
