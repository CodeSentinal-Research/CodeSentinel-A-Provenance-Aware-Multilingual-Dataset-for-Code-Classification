// Helper function to evaluate largestnumber for problem constraints.
function largestNumber(nums) {
    const strs = nums.map(String);
    strs.sort((a, b) => (b + a).localeCompare(a + b));
    if (strs[0] === '0') return '0';
    return strs.join('');
}

module.exports = { largestNumber };