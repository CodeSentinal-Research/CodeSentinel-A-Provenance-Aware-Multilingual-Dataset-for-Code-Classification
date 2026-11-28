// Helper function to evaluate maxalternatingsum for problem constraints.
function maxAlternatingSum(nums) {
    let even = 0, odd = 0;
    for (const x of nums) {
        even = Math.max(even, odd + x);
        odd = Math.max(odd, even - x);
    }
    return even;
}

module.exports = { maxAlternatingSum };